# PDFTranslator
What is the PDF Translor?
The PDF Translator is a project created for Foxit Student Challenge.  This is a starter project which has a lot of the code completed and is waiting for a student to complete the Challenge.

##Here are the challenges
1. When a PDF is open, user are able to select a word in the PDF, right click, select Translate, and display the translation.
2. Be able to translate to and from at least 3 different languages
3. Have a option to select the language the user to translate to.

##How to build and run the project?
1. Download and install Foxit PhantomPDF https://cdn06.foxitsoftware.com/pub/foxit/phantomPDF/desktop/win/10.x/10.1/en_us/FoxitPhantomPDF1011_enu_Setup_Website.msi
2. Install Microsoft Visual Studio 2017
3. Open "PDFTranslator\Samples\Starter\Starter.sln" with Visual Studio 2017
4. Install any project dependancy Visual Studio 2017 indicates that you are missing.
5. Open Windows Explorer and go to "C:\Program Files (x86)\Foxit Software\Foxit PhantomPDF\"
6. Right click on the folder "plugins" and choose properties
7. Click on the "Security" Tab
8. Click on "Edit"
9. Select "Users" and check the box "Full Control"
10. Click "Apply"
11. Go back to Visaul Studio 2017 and build and run the project.

##What do you get when you run the sample now?
1. Open Foxit PhantomPDF
2. Open the any PDF with text content
3. Select text in the PDF
4. Right click
5. Select Translate
6. See message selected text displayed.  To complete this project, user should go to "PDFTranslate\Samples\Starter\Starter.cpp" and the function TranslateAction and traslate the valuate outText before it is displayed.

##Where can I find Foxit PhantomPDF Plug-in APIs?
Please see "PDFTranslate\Document\Foxit Reader PDF API Reference.pdf"

##Need Support?
For Support, please contact Huy_Tran@foxitsoftware.com
Join our Discord: https://discord.gg/5KGszf4H
