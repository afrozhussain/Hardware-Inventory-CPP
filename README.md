# Hardware-Inventory-CPP
Hardware Inventory Program in C++

I love to write code in C++ and this project was hosted on freelancer.com I had some time so attempted to solve and presenting here just for fun :)

Objective:
Write a database to keep track of tools, their cost and number.  Your program should initialize hardware.dat to 100 empty records, let the user input a record number, tool name, cost and number of that tool. Your program should let you delete and edit records in the database.  The next run of the program must start with the data from the last session.

Example Program Session:
(First Run)Enter request
1 – Input new tool or update an existing tool
2 – Delete a tool
3 – List all tools
4 – Exit
? 3

Record #  Tool name           Quantity  Cost

Enter request

1 – Input new tool or update an existing tool
2 – Delete a tool
3 – List all tools
4 – Exit
? 1

Enter record number ( 1 to 100, 0 to return to main menu )

? 5

Enter tool name, quantity, cost

? saw 102 12

Enter record number ( 1 to 100, 0 to return to main menu )

? 7

Enter tool name, quantity, cost

? hammer 75 8

Enter record number ( 1 to 100, 0 to return to main menu )

? 0

Enter request

1 – Input new tool or update an existing tool
2 – Delete a tool
3 – List all tools
4 – Exit
? 3

Record #  Tool name           Quantity  Cost
5               saw                      102       12.00
7               hammer                75        8.00

Enter request

1 – Input new tool or update an existing tool
2 – Delete a tool
3 – List all tools
4 – Exit
? 4

Press any key to continue . . .
(Second Run)Enter request

1 – Input new tool or update an existing tool
2 – Delete a tool
3 – List all tools
4 – Exit
? 3

Record #  Tool name           Quantity  Cost
5               saw                     102       12.00
7               hammer               75        8.00

Enter request

1 – Input new tool or update an existing tool
2 – Delete a tool
3 – List all tools
4 – Exit
? 4

Press any key to continue

C++ code is as below, you may use Dev-C++ compiler to run following code.