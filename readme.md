This repository contains the code submitted as part of my thesis project for the University of Arizona College of Optical Sciences. It was the initial development performed for a system consisting of a CCD camera and an OCT imaging system. The full thesis is included in this repository, as well as setup instructions for the code. While the code can be built, all pieces of hardware are required in order to run the application as there is no simulator mode at present. 

Proprietary Software:

This repository does not include dependencies that needed to be purchased from Princeton Instruments and AlazarTech. See the following links for more information about those software packages. 
AlazarTech, ATS-GPU-OCT library. Please note that the ATS-GPU-BASE must also be purchased, as well as an AlazarTech : https://www.alazartech.com/en/product/ats-gpu-oct/31/#productRelationsContainer 
Princeton Instruments. The code in this repository should work for any PIXIS CCD camera, but it has only been run with the PIXIS 1024B CCD. I recommend contacting Princeton Instruments and requesting the sample code to ensure compatibility with your camera: https://www.princetoninstruments.com/products/pixis-family

Computer and Repository Setup Instructions:

This is a complete walkthrough of the computer setup and software installation process performed on October 12, 2018 on the dedicated Falloposcope computer. For completion, this description assumes that you are setting up a completely new system and walks through all steps required. Please follow these instructions exactly. NOTE: It is possible, with ongoing updates to drivers and Windows 10 itself that things will not work in the future exactly as they did before. This walkthrough includes as much information as possible to explain not only what was done, but why. Hopefully this will help with your troubleshooting!
1.	Computer Specifications: If you’re starting from scratch, these are the settings of the computer the laboratory ordered from NorTech:

![image1](images/CompSpecs.png)
 
The critical components are the X299 chipset, as well as the AMD Pro WX7100 GPU. The high-end chipset provides enough lanes for data transfer between the AlazarTech board and the GPU. Without them data processing cannot happen as quickly. If you are considering a different configuration, this functionality is what’s required. 

2.	Install Updated GPU Drivers, Enable Direct GMA: You will need to change the driver settings of the AMD card to allow for Direct Graphics Memory Access (GMA). This will allow data from the AlazarTech board to be written directly to the AMD card. The drivers used by the optics tissue laboratory are saved (win10-64bit-radeon-pro-software-enterprise-18.q3.1-oct1.exe), as well as the installation instructions (AMD Driver Installation Guide), but it’s recommended you download the latest driver software from the AMD website. 

Install all possible packages and restart the computer. When this is complete, you should be able to right-click to access the FirePro settings.

![image2](images/AMDFireproSettings.png)
 
Select “Advanced”, then “SDI/DirectGMA”. Check the box and move the slider as high as it will go. 

![image3](images/AMDDirectGMASettings.png)
 
Restart the computer for this change to take effect. 

3.	Install Visual Studio 2017 Community Edition: All software was developed in Visual Studio 2017 for C++/CLI. At the time of this writing, the Community version of Visual Studio is free, hopefully this is still the case or Microsoft will have difficulty attracting 3rd party developers to its platform. Anyway, several sub-packages must also be installed. Download and run the Visual Studio 2017 Installer, then select the following packages to include in the installation of the Community Edition. The total file size should be around 8 GB.
a.	.NET Desktop Development
b.	Desktop Development with C++
c.	Along the right hand side, there is a section titled “Installation Details”. Under “Desktop Development with C++”, be sure to check “C++/CLI Support” or you will be unable to debug the software. 
d.	With these three options selected, click “Install While Downloading” in the lower right-hand corner.
e.	Restart the computer when prompted. 

![image4](images/VS2017InstallerPackageSelections.png)
 
4.	Install AlazarTech Packages: There are 3 sets of material to install. As stated above, these are not included in the Repository and must be purchased from AlazarTech. Once acquired, all 3 libraries should install to the main folder “C:\AlazarTech”. Do NOT modify this unless you know what you’re doing, and know that you will need to point the project in this repository to the new location.
a.	ATS-SDK
b.	ATS-GMA v4.0.0
c.	ATS-GMA-OCT v4.0.0

5.	Install PICam: Run the installation for PIXIS software drivers and dependencies, called PICam. As stated above, a camera will need to be purchased from Princeton Instruments. Once acquired, install PICam. This project assumes that dependency files will be installed to “C:\Program Files\Princeton Instruments\PICam”.
a.	Install to the default directory “C:\Program Files\Princeton Instruments\PICam”. 
b.	Select “Custom” installation and check the box next to “SDK” to install the PICam software development tool kit. 
c.	As it installs, it will ask about various sub-packages. Click “Yes” as they come up. 
d.	Restart the computer. 

6.	Install Microsoft Expression Encoder 4: Not included in this repository, but can be downloaded for free (at the time of this writing) at "https://download.cnet.com/Microsoft-Expression-Encoder-4/3000-18515_4-75450292.html". This will install the video codec required to play back the video files of the screen recordings. This may not be available elsewhere, so it’s recommended you use the installer. NOTE: There is a separate program which performs the screen recording. Source code is in a separate folder named “ScreenRecorder” and it’s written in a 32 bit C++ console application. This doesn’t affect you unless you’re replacing the screen recording functionality. 
 
Some details about the code

The code used to access data from the AlazarTech digitizer, and from there the waterfall B-Scan image, originated in the AlazarTech sample code "Inversion_application", which can be viewed following purchase of the ATS-GMA-OCT library. These are the changes to that code, specifically the board parameters:
1.	Update code to be compatible with VS2017 Community Edition. This is done automatically by running the .sln file.
2.	Edit function “AlazarSetCaptureClock()”, change sample rate to “SAMPLE_RATE_180MSPS” to match the sample rate of the ATS-9462 board. 
3.	On line 249, change the line to read “autoDMAFlags = ADMA_EXTERNAL_STARTCAPTURE | ADMA_NPT”; by default the last section is “ADMA_CONTINUOUS_MODE”.
4.	Comment out lines 333-338, which sets the pack mode. Comment out lines 291-292, which calls the function to change the pack mode. Comment out line 270, which sets this variable in the first place (it’s not necessary anywhere four our setup, the board doesn’t support it, and when you try to call the function it throws an error. 
5.	Set the trigger source ID to TRIG_EXTERNAL. This is done in line 131, it is the 4th parameter in the function AlazarSetTriggerOperation().
6.	//Change UserDefinedContext to True, the default is false. This is in line 273.

Rendering Bitmaps: Both the CCD and OCT imaging functions require data to be rendered as a Bitmap. The following are a few critical notes on building the Bitmaps from the raw data returned from each device.
1.	Use Lockbits: The fastest way to read and write data from the bitmap is to lock the bits in the bitmap object to read and or write data directly to them. The bitmap object is a managed object in the .NET framework, and it is necessary to perform the specific Lockbits operation to remove this automatic management, allowing data to be written directly. C++ allows for direct memory writing using pointers. Please see the code for how this is implemented. 
2.	Do NOT use ImageLockMode::ReadWrite: There are several modes to use to read and write data, and this one is incredibly slow. In the case of the B-Scan imaging, it is necessary to read old data, and write new data, to the same image. The fastest way to do this is to first use ImageLockMode::ReadOnly, read the existing data to a new buffer, and unlock the pixel buffer. Then, lock the pixel buffer again with ImageLockMode::WriteOnly, and perform the writing operation. 
3.	To display the Bitmap in the PictureBox, use AutoSize::Zoom: There are several ways to resize bitmaps to fit in the available space on the GUI. Zoom mode is one of the fastest as no interpolation is used to render the image as long as the aspect ratio is the same for both the bitmap and the PictureBox it is displayed in. Be careful not to use an image resizing mode like stretch, which will perform an interpolation on the bitmap and slow down rendering speeds considerably. 
