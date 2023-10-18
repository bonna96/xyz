
# xyz_project
This is a Phone Book Management system with c programming language.

This program saves,changes and searches mobile numbers of different persons.It includes stdio.h,stlib.h,conio.h,string.h header files for using its required functions.The required sizes,numbers also define first in the code.There are some functions that have been used for the work.

   * addmobile(): This function asks the user to enter the details of a new person and appends them to the 
                  strime of the file named "num.txt".
  
   * search_login(): This function asks the user to enter the name and email of a person and searches for them  
                     in the read mode of the file “num.txt” by strcmp() function. If found, it display    
                     details of the person and returns their index in the file.

   * changenumber(): This function takes an index as a parameter and changes the mobile number of the person at 
                     that index in the file “num.txt” after entering choice 2(search number) then we will be able
                     to change the number. It uses fseek() ,holds a file, an offset, and a position 
                     to move the file pointer to the correct position and fprintf() to overwrite the old number 
                     with the new one.

   * deletenumner(): This function works by creating a temporary file named “tempr.txt” and copying all the 
                     records from “num.txt” except the one that matches the given index. Then it deletes the 
                     original file and renames the temporary file as “num.txt”. This way, the record at the 
                     given index is effectively removed from the file

     .![Screenshot 2023-10-19 015645](https://github.com/bonna96/xyz/assets/148382783/ca75a70d-3372-49d1-89a7-a81f41f843ab)
![Screenshot 2023-10-19 015254](https://github.com/bonna96/xyz/assets/148382783/d5bf855c-95d3-4b93-a1b3-f77b5858f07e)![Screenshot 2023-10-19 015152](https://github.com/bonna96/xyz/assets/148382783/f5d4a6f4-3199-488b-baaa-9d4c484d19d3)![Screenshot 2023-10-19 023433](https://github.com/bonna96/xyz/assets/148382783/d06db1cc-1a0d-44bf-b1e7-df59b76bd770)![Screenshot 2023-10-19 023501](https://github.com/bonna96/xyz/assets/148382783/b8876f16-4806-4e63-b0f6-3e8ffe2185d8)



To run this project you need codeblocks or else you can not see the color effect implemented on console and mingw(compiler and debugger) beside you have to install gcc in the command prompt.
   you can also check if gcc is installed in your pc by gcc --version command.
