#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>


using namespace std;

struct HARDWARE_ITEM{
	
	int record_num = 0;
	char tool_name[100];
	int quantity = 0;
	float cost =0.0;
	bool is_active = 0;
};	

 HARDWARE_ITEM records[99];


void CreateEmptyDatabase(void)
{	
	int rec_num = 0;
		
	for(int i=0;i<100; i++)
	{
		rec_num ++;
		records[i].record_num = rec_num;		
		//fs.write( (char*)&records[i], sizeof(HARDWARE_ITEM) );		
	}

	fstream fs("hardware.dat", fstream::out|fstream::app|fstream::binary );
	fs.write( (char*)&records, sizeof(HARDWARE_ITEM)*100 );
	fs.close();
	
	}

void AddUpdateRecord()
{
	
	fstream fs("hardware.dat", fstream::in|fstream::out|fstream::binary );
	fs.write( (char*)&records, sizeof(HARDWARE_ITEM)*100 );
	fs.close();
}


void ListItems()
{
	
	cout << setw(10) << left << "Record #" 
		 << setw(35) << left << "Tool name" 
		 << setw(12) << left << "Quantity"
		 << setw(5)  << left <<  "Cost"  <<"\n";
		 
	
	cout << setw(10) << left << "---------" 
		 << setw(35) << left << "-------------------------------" 
		 << setw(12) << left << "----------"
		 << setw(5)  << left <<  "-----"  <<"\n";
	
	
	fstream fs("hardware.dat", fstream::in|fstream::binary );	
	//fs.open("hardware.dat", fstream::in | fstream::binary | fstream::ate);
	
	HARDWARE_ITEM item;

	int items_count = 0;

	while( fs.read( (char*)&item, sizeof(HARDWARE_ITEM)) )
	{		
		
		//items_count = items_count + 1;
		
	if (item.is_active == 1)
		{
		
		cout << setw(10) << left << item.record_num 
			 << setw(35) << left << item.tool_name 
			 << setw(12) << left << item.quantity
			 << setw(5)  << left <<  item.cost  <<"\n";
		}

	}
		 
		//cout << endl << "Total items :" << items_count << endl;	
		 

	fs.close();

		 
	
}



int main()
{

	fstream dbfile;
	dbfile.open("hardware.dat", fstream::in);

	if (!dbfile.is_open())
	{
		CreateEmptyDatabase();
	}
	else
	{
		dbfile.read( (char*)&records, sizeof(HARDWARE_ITEM)*100 ); 
		dbfile.close();
	}
	

  int option = 0;		

while(1)
{

	
  cout << "\nEnter Request\n";
  cout << "1 - Input new tool or update an existing tool\n";
  cout << "2 - Delete a tool\n";
  cout << "3 - List all tools\n";
  cout << "4 - Exit\n";
  
  cout << "? ";
  cin >> option;
  
  int rec_num;
  
  switch (option)
  {
  	
  	
  case 1:	//	Input new tool or update an existing tool
  
  	
  	cout << "Enter record number ( 1 to 100, 0 to return to main menu )" << endl << "? ";
  	  	
  	cin >> rec_num;
  	
  	if (rec_num == 0)
  	{
  		break;		  	
	}
	
	cout << "Enter tool name, quantity, cost " << endl << "? ";  	
	cin >> records[rec_num-1].tool_name;
	cin >> records[rec_num-1].quantity;
	cin >> records[rec_num-1].cost;
	
	 
  	records[rec_num-1].is_active = 1;
  	
  	AddUpdateRecord();
  
  	break;
  	
  case 2:	//	Delete a tool
  	
  	cout << "Enter record number ( 1 to 100, 0 to return to main menu )" << endl << "? ";
  	  	
  	cin >> rec_num;
  	
  	if (rec_num == 0)
  	{
  		break;		  	
	}
	strcpy(records[rec_num-1].tool_name, "");
	records[rec_num-1].quantity = 0;
	records[rec_num-1].cost = 0;	 
  	records[rec_num-1].is_active = 0;
  	
  	AddUpdateRecord();
  
	
	break;
	
  case 3:	//	List all tools
  	
	  ListItems();
	
	break;
  	
  case 4:	//	Exit.
  	return 0;
  	break;
  
  }  
  
}

return 0;
}
