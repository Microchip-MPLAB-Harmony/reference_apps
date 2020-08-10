# Copyright 2019-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import concurrent.futures
import time

class Multiplexer:
    class Task:
        def __init__(self, executeCallback, dispatchCallback):
            self.ExecuteCallback = executeCallback
            self.DispatchCalback = dispatchCallback
            self.Future = None

    def __init__(self, heartbeatInterval):
        self._heartbeatInterval = heartbeatInterval

        self._tasks = []

    def AddTask(self, executeCallback, dispatchCallback):
        self._tasks.append(Multiplexer.Task(executeCallback, dispatchCallback))

    # Waits for one; dispatches.
    # Returns False if a task's execute callback returns None, indicating that it is shutting down.
    def Wait(self) -> bool:
        futures = []
        for task in self._tasks:
            if task.Future is None:
                task.Future = task.ExecuteCallback()
                if task.Future is None:
                    return False
            futures.append(task.Future)

        doneFutures, pendingFutures = concurrent.futures.wait(
            futures,
            return_when = concurrent.futures.FIRST_COMPLETED,
            timeout = self._heartbeatInterval)

        for task in self._tasks:
            future = task.Future
            if future in doneFutures:
                task.DispatchCalback(future.result())
                task.Future = None

        return True