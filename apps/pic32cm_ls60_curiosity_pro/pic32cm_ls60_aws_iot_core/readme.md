---
grand_parent: 32-bit MCU Reference Applications
parent: PIC32CM LS60 Curiosity Pro Evaluation Kit
title: AWS Cloud IoT Core Application
nav_order: 2
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

<h1> AWS Cloud IoT Core Application on PIC32CM LS60 Curiosity Pro Evaluation Kit </h1>
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/pic32cm_ls60_aws_iot_core" > Download </a> </h2>


---

# [AWS Cloud IoT Core Application on PIC32CM LS60 Curiosity Pro Evaluation Kit](https://bitbucket.microchip.com/projects/MH3/repos/reference_apps/pull-requests/430/pic32cm_ls60_aws_iot_core/readme.md)

# | [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/pic32cm_ls60_aws_iot_core.zip) |

<h2> Description: </h2>

> The PIC32CM LS60 Curiosity Pro Evaluation Kit is ideal for evaluating and prototyping with the secure and ultra-low power PIC32CM LS60 ARM® Cortex®-M23 based microcontrollers. The MCU integrates TrustFLEX ECC608 secure subsystem & Arm® TrustZone® Technology in one package. This specific development board can be pre-provisioned for AWS IoT Core; The application demonstrates MQTT data transfer of light and temperature sensor data from IO1Xpro to AWS IoT core .

## Key Highlights of [ PIC32CM LS60 Curiosity Pro Evaluation Kit](https://www.microchip.com/en-us/development-tool/EV76R77A):

* Additional sensors can be interfaced using "click boards" through an on-board [mikroBUS connector](https://www.mikroe.com/click).
* - Extension headers
  - Arduino Uno header connectors
  - mikroBUS socket
  - Embedded debugger
  - USB interface, Host or Device
  - Embedded current measurement XAM with Data Visualizer support for real-time power measurement
  - One Touch button
  - One Potentiometer

<h2> Features of PIC32CM LS60 Curiosity Pro Evaluation Kit: </h2>

* Microcontroller peripheral libraries and Middleware are based on the MPLAB Harmony v3 Software framework.
* MPLAB X IDE-based project.
* Command Line Interface (CLI) support for Wi-Fi credentials configuration.
* 2 User LED's and Push buttons.

<h2> Components Used: </h2>

- [PIC32CM5164LS60100 microcontroller](https://www.microchip.com/en-us/product/PIC32CM5164LS60100)
- [PIC32CM LS60 Curiosity Pro Evaluation Kit](https://www.microchip.com/en-us/development-tool/EV76R77A)
- [ATWINC1510 Wi-FI module](https://www.microchip.com/wwwproducts/en/ATwinc1500)
- [I/O1-Xpro Extension kit](https://www.microchip.com/en-us/development-tool/ATIO1-XPRO)
- [MIC5528 Voltage Regulator](https://www.microchip.com/en-us/product/MIC5528)

<h2> Software/Tools Used: </h2>

<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer [Project Manifest](./firmware/NonSecure/firmware/src/config/pic32cm_ls60/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/pic32cm_ls60*

- Refer the [Release Notes](../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools)  

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

<h2> <a id="aws_demo_account_setup"> </a> </h2>

<h2> AWS Account Setup </h2>

<details>
  <summary> Details
</summary>

To run the AWS Cloud IoT core solution, an AWS account is required. The following are the steps to configure an AWS account.

Amazon Web Services (AWS) provides computing services for a fee. Some are offered for free on a trial or small-scale basis. By signing up for your AWS account, you are establishing an account to access a wide range of computing services.

Think of your AWS account as your root account for AWS services. It is very powerful and gives you complete access. Be sure to protect your username and password. You control access to your AWS account by creating individual users and groups using the Identity and Access Management (IAM) Console. You also assign policies (permissions) to the group from the IAM Console.

<h3> Create your own AWS account </h3>

1. Create AWS account. Go to [AWS](https://aws.amazon.com) website and follow instructions to create your own AWS account. Additional details can be found at [create and activate a new AWS account.](https://aws.amazon.com/premiumsupport/knowledge-center/create-and-activate-aws-account)  

2. Secure root account with MFA (multi-factor authentication)  
   This is an important step to better secure your root account against attackers. Anyone logging in not only needs to know the password, but also a constantly changing code generated by an MFA device.  
   AWS recommends a number of MFA device options at the following link: https://aws.amazon.com/iam/details/mfa/  
   The quickest solution is a virtual MFA device running on a phone. These apps provide the ability to scan the QR code AWS will generate to set up the MFA device.  
   
       a. Return to https://aws.amazon.com/ and click the Sign In to the Console.  
       b. If it asks for an IAM user name and password, select the Sign-in using root account credentials link.  
       c. Enter the email and password for your AWS account.
       d. Under Find Services search for IAM and select it to bring up the Identity and Access Management options.  
       e. Click on Activate MFA (Multi-factor Authentication) on your root account.  
       f. Create an admin IAM user AWS best practices recommend not using your root account for standard administrative tasks, but to create a special admin user for those tasks. See https://docs.aws.amazon.com/IAM/latest/UserGuide/best-practices.html#lock-away-credentials  

3. Follow the instructions at https://docs.aws.amazon.com/IAM/latest/UserGuide/getting-started_create-admin-group.html for creating an admin user.  

4. Enable MFA (multi-factor authentication) for the admin user. See https://docs.aws.amazon.com/IAM/latest/UserGuide/best-practices.html#enable-mfa-for-privileged-users

<h3> Configuring the account using CloudFormation Templates  </h3>

The usage of a custom PKI with TrustFLEX devices uses the Just-In-Time Registration (JITR) feature of AWS IoT Core. This feature requires a number of resources setup with an AWS account to work. The creation of these resources is automated through the AWS CloudFormation service.  

1. Sign into the [AWS console](https://aws.amazon.com/) using the admin user created in the previous section.  

2. Change to region to ***US East (Ohio) (a.k.a. us-east-2)***. This is done from a dropdown in the top right of the console webpage after logging in.  

3. Under ***Find Services*** search for ***CloudFormation*** and select it to bring up that service.  

4. Click ***Create Stack*** button.  

5. Select Upload a template file from the page of the stack creation.   

6. Click Choose file and upload the **aws-zero-touch-full-setup.yaml** file.  
    **Note**: If running from a China region, you’ll need to select the aws-zero-touch-full- setup-cn.yaml instead. These files are available in **~/.trustplatform** folder.  

7. Click ***Next*** to move on to the stack details.  

8. Enter ***TrustFLEX*** as the stack name. Actual name isn’t important, just has to be unique.  

9. Enter a password for the user that will be created to run the demo under UserPassword.  

10. Click ***Next*** to move on to the stack options. Nothing needs to be changed here.  

11. Click ***Next*** to move on to the stack review.  

12. Check the acknowledgment box regarding IAM resources at the bottom of the page.  

13. Click ***Create Stack*** to start the resource creation.  

14. Wait until the stack creation completes. This can take a few minutes. Once done, the stack you created will show as CREATE_COMPLETE.  

15. Save demo credentials. Click the Outputs tab for the stack to see the credentials to be saved.  

16. Save the credentials to **aws_credentials.yaml** file in **"~/.trustplatform/aws_credentials.yaml"** folder.  
    **Note**: **~** Indicates windows home directory is /user/username 

</details>

<h2> <a id="AWS_Cloud_IoT_Provisioning_Guide"> </a> </h2>

<h2> AWS Cloud IoT Provisioning Guide </h2>

<details>
  <summary> Details
</summary>

<span style="color:red"> **If this is the first time you are building/running this version of the demo, you must complete this step before proceeding further. Otherwise, you may skip this step.** </span>

1. Install Trust Platform Design Suite version 2 [TPDSv2](https://www.microchip.com/en-us/product/SW-TPDSV2#Software)

2. Launch Trust Platform Design Suite v2 from windows search bar, a window launches as shown below  
   
   <img src ="./images/tpds1.png">

3. Select "Trust Platform Design Suite" in **webviews** and Click on **Usecases**  
   
   <img src="./images/tpds2.png">

4. In **Select Security Solution**, Under **Use Cases** select **AWS IoT Authentication**
    ![](./images/tpds3.png)

5. Scroll Down and in **Available solution by provisioning flow** select **AWS IoT Authentication** under **PIC32CMLS60**  
   
   <img title="" src="./images/tpds4.png" alt="">

6. A Usecase gets launched. click on **AWS IoT Authentication-PIC32CMLS60** from the **Usescases**  
   
   <img title="" src="./images/tpds6.png" alt="">

7. AWS Cloud Connect – IoT Authentication page launches as shown below  
   
   <img title="" src="./images/tpds6.png" alt="">

8. Scroll down and select PIC32CMLS60 Curiosity Pro Evaluation kit if not selected  
    ![](./images/tpds12.png)

9. Connect both the debug and Traget USB to PIC32CMLS60 Curiosity pro evaluation kit to PC running Trust Platform Design Suite.Connect the WINC1500-Xpro to EXT3 of the Kit.

10. Scroll down to transaction diagram  
    
    <img src="./images/tpds7.png">

11. Click on Icon **1** and wait till a green right mark appears.  
    
    <img src="./images/tpds8.png">

12. Sequentially Click on Icon **2**, **3** and **4**  
    
    <img title="" src="./images/tpds9.png" alt="">

13. Note the output in the output window on the right side

14. Once the use case steps are executed successfully, click on **C Source Files** and navigate to **.trustplatform\pic32cmls60_cloud_connect** and copy the **aws_connect.h** file
    
    ![](.\images\tpds13.png)

15. Replace the aws_config.h file in the **project folder(pic32cm_ls60_aws_iot_core)** with the file that was copied in the above step
    
    ![](.\images\tpds15.png)

</details>

<h2> <a id="WINC_Firmware_upgrade"> </a> </h2>

<h2> ATWINC1510 Wi-Fi controller module firmware and AWS Root certificates upgrade Guide </h2>

<details>
  <summary> Details
</summary>

- Navigate to the **utilities** folder inside the project directory **(pic32cm_ls60_aws_iot_core)**  
  
  ![](.\images\sb1.png)

- Follow the steps in readme.md file inside the folder to do the WINC firmware upgrade.

</details>

<h2> Application Demonstration </h2>

<details>
  <summary> Details
</summary>

The following sections describes the steps to run the application.  

<h3> 1. How to setup the PIC32CMLS60 Development Board  </h3>

- Connect the Debug USB port of PIC32CMLS60 Curiosity pro evaluation kit to the host PC's USB port to power-up the board.  
  
  <img title="" src="./images/kitsetup.png" alt=""> 

- The board must be connected through a USB port to perform a firmware upgrade 

- Connect the WINC1500-Xpro to EXT3 and IO1-Xpro to EXT2 of the PIC32CMLS60 Curiosity pro evaluation kit.

- Use MPLAB X IDE to Program. 

- Configure the Wi-Fi Credentials using **Wi-Fi configuration through CLI** method explained Below.  

<h3> 2. Firmware upgrade and Wi-Fi configuration process </h3>

<h4> Firmware upgrade through MPLAB X IDE </h4>

- Connect the kit to the PC.Open MPLABX IDE and Click on the open project icon as shown below  
  
    ![](.\images\tpds16.png) 

- Open the project file **(pic32cm_ls60_cpro_NonSecure.X )** file as shown below
  
  ![](.\images\tpds14_1.png)

- Once the project is opened in the IDE Click on the **Make and Program** icon as shown below and wait till the **Programming complete** message.
  
  ![](.\images\tpds17.png)

<h4> Firmware upgrade through MPLAB X IDE </h4>
- Most developers usually follow this method to program the .hex file from the MPLAB X IDE environment.(Navigate to hex folder inside the project directory as shown in the below image)

![](./images/firmware_upg1.png)

<h4> Wi-Fi configuration through CLI </h4>

- Open a terminal application on the host PC for the virtual COM port of the connected PIC32CMLS60 Curiossity pro evaluation kit, with 115200-8-None-1 settings.  

- Just enter the below command to set the Wi-Fi credentials.<br>
  
    ***`wifi < SSID >,< PASSWORD >,< SECURITY TYPE >`***  
    example : ***`wifi MCHP_test,Asdfghjk,2`***  
  
  **Note**:No need of repeating this step every time while running the demo, Device remembers last used WiFi credentials and try to connect to it. If WiFi credentials changes, this step should be performed.

<h3> 3. Running the demo application </h3>

- After a successful connection, the PIC32CMLS60 Curisity Pro Evaluation kit pushes the real-time light and temperature sensors data of the IO1Xpro to the AWS IoT cloud. Toggling of LED0 (Green LED) indicates the same.
  
  Red LED (LED1) indicates that the WiFi is not connected.
  
  **Note**: Only Temperature data is pushed by default.Light data is pushed when SW0 is pressed and pressing SW1 stops the publishing of Light sensor data.
  
    ![](./images/aws.png)  
  
    **Note :** AWS cloud path to visualize the data pushed from the device "AWS IOT > Manage > Things > ThingNAME (ThingNAME = device_serialnumber) > classic Shadow"  

</details>

<h2> The AWS Lambda service </h2>

<details>
  <summary> Details
</summary>

AWS Lambda is a service that enables code to be run in the cloud without worrying about things like provisioning, server management, and scalability. It natively supports many different programming languages, and interfaces with a wide range of other AWS services to facilitate cloud development.

we will use AWS Lambda to transfer temperature and light sensor data from SAM-IoT Development Board to cloud watch. The main concept that we will focus on is how to route data between AWS Lambda and AWS IoT Core.

1. Sensor data is sent from connected devices to the AWS Cloud as MQTT messages.
2. The data is forwarded from AWS IoT Core to AWS Lambda, where it is routed to cloud watch for plotting the graph.

<h3> Creating a Role in AWS IAM </h3>

1. Sign in to the ***[AWS Management Console](https://aws.amazon.com/console/)*** and select the ***IAM*** service.

2. Select ***Roles*** under ***Access Management*** in the menu on the left-hand side

3. Click ***Create role***.

4. Select ***AWS service*** as the trusted entity.

5. Select ***Lambda*** as the use case.

6. Click ***Next: Permissions***.

7. Attach the ***AWSIoTDataAccess***, ***CloudWatchFullAccess*** and ***AWSLambdaBasicExecutionRole*** permission policies by using the search bar and ticking the relevant boxes. This will allow our Lambda function to send data to the AWS IoT Core and use Amazon CloudWatch logs. We will not cover Amazon CloudWatch in this tutorial, but it could be a useful tool for debugging your application later on.

8. Click ***Next: Tags***.

9. Click ***Next: Review***.

10. Enter ***Lambda_IoT_role*** as the Role name.

11. Click ***Create role***

<h3> Designing an AWS Lambda function </h3>

<h4> Creating an empty Lambda function </h4>

AWS Lambda is a service that enables us to run code in the cloud without worrying about server management. It can be set up to send and receive data from many different services, such as AWS IoT Core, which we will make use of in this tutorial. To create an AWS Lambda function:

1. Sign in to the ***AWS Management Console*** and select the ***Lambda*** service.

2. Select ***Functions*** in the menu on the left-hand side.

3. Click on ***Create function***.

4. Choose ***Author from scratch***.

5. Enter ***iot_Core_to_CwMetrics*** as the Function name.

6. Select ***Python 3.8*** as the Runtime.

7. Expand ***Choose or create an execution*** role under ***Permissions*** and select ***Use an existing role***.

8. Select the ***Lambda_IoT_role*** that we defined earlier

9. Click on ***Create function***.

When the AWS Lambda function has been successfully created, the user should be redirected to the Configuration page for the iot_Core_to_CwMetrics function. This page can also be found by selecting Functions in the menu on the left-hand side in AWS Lambda and then selecting the function from the list.

<h3> Triggering the Lambda function for relevant MQTT packages </h3>

The next step is to configure the Lambda function to trigger when messages containing sensor data are published over MQTT in AWS IoT Core:

1. On the Lambda function's configuration page, expand the ***Designer*** panel.

2. Click on ***Add trigger***.

3. Select ***AWS IoT*** as the trigger in the dropdown menu.

4. Select ***Custom IoT rule***.

5. In the ***Rule*** dropdown, select ***Create new rule***.

6. Enter ***RouteSensorData*** as the Rule name.

7. Enter ***SELECT * FROM "$aws/things/ThingName/shadow/#"*** as the Rule query statement.  
   **NOTE :** ThingName is the unique serial number of the device

8. Click ***Add***.

<h3> Implementing the Lambda function  </h3>

1. Ensure that the ***iot_Core_to_CwMetrics*** function is selected in the Designer panel.

2. Paste the following Python code in the editor in the Function code panel
   
   ```
    import json # Python library for dealing with JSON objects
    import boto3 # boto3 is the AWS SDK for Python
   
    cloudwatch = boto3.client('cloudwatch')
   
    #Define payload attributes that may be changed based on device message schema
    ATTRIBUTES = ['temperature','light','state','reported']
   
    # Define CloudWatch namespace
    CLOUDWATCH_NAMESPACE = "thingls60/MonitorMetrics"
   
    # Define function to publish the metric data to CloudWatch
    def cw(topic, metricValue, metricName):
        metric_data = {
            'MetricName': metricName,
            'Dimensions': [{'Name': 'topic', 'Value': topic}],
            'Unit': 'None',
            'Value': metricValue,
            'StorageResolution': 1
        }
   
        cloudwatch.put_metric_data(MetricData=[metric_data],Namespace=CLOUDWATCH_NAMESPACE)
        return
   
    # Define the handler to loop through all the messages and looks to see if the message    attributes
    # include light or temp and calls the cw() function if so to publish the custom metrics    to Amazon CloudWatch
    def lambda_handler(event, context):
        my = list(event.values())
        my_list = list(my[0].values())
        print(my_list[0])
   
        for e in my_list[0]:
            print("Received a message: {}".format(str(e)))
            print(e) # Potential test point
   
            # Iterate through each attribute we'd like to publish
            for attribute in ATTRIBUTES:
                # Validate the event payload contains the desired attribute
                if attribute  in e:
                    print("publishing {} to CloudWatch".format(attribute))
                    cw("PIC32CMLS", my_list[0][attribute], attribute)
        return event
   ```

3. Click ***Save***

<h3> Visualizing sensor data in cloudwatch </h3>
1. Search **CloudWatch** in AWS search box and open it  
   <img src = "./images/cw1.png">
2. Click on **Dashboard** on the right side of the window under CloudWatch  
   <img src = "./images/cw2.png">
3. Click on **Create Dashboard**  
   <img src = "./images/cw3.png">
4. Enter Dashboard name as **pic32cmls60_dashboard** and click on Create Dashboard  
   <img src = "./images/cw4.png">
5. Under Add widget Select **Number**  
   <img src = "./images/cw5.png">
6. Under Add metric graph, select **thingls60/MonitorMetrics** and then **topic**  
   <img src = "./images/cw6.png">  
   <img src = "./images/cw7.png">
7. Under **Metrics**, select BOTH **PIC32CMLS** temperature and light metrics  
   <img src = "./images/cw8.png">
8. Navigate to **Graphed metrics** and change the period to 1 second in both temperature and light metrics. Then click on **Create widget**
   <img src = "./images/cw9.png">
10. Click **Save dashboard**

11. This Dashboard page refreshes every 10 seconds and update the sensor data.
    **Note : ** Your custom dashboard can be found in **CloudWatch > Dashboards > your dash board name** **(here it is pic32cmls60_dashboard).The *non-secure temperature* data is shown by default.To view *secure light sensor* data press SW0 on the PIC32CMLS60 curiosity pro evaluation kit.To stop viewing it press SW1**.                

</details>

<h2> Reference: </h2>

- For more details on the application usage, functionality and other details, refer to the [PIC32CM LS60 Curiosity Pro Evaluation Kit User Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU32/ProductDocuments/UserGuides/70005443E.pdf)

<h2> Comments:    </h2>

- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
  - [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
  - [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  
  - <span style="color:blue"> **MPLAB Harmony v3 is also configurable through MPLAB Code Configurator (MCC). Refer to the below links for specific instructions to use MPLAB Harmony v3 with MCC.**</span>
    - [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
    - [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
    - [Getting Started with MPLAB Harmony v3 Using MPLAB Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
    - [MPLAB Code Configurator Content Manager for MPLAB Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)

<h2> Revision: </h2>
- v1.6.0 - released demo application
