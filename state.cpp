
#include "state.h"
#include <iomanip>  //need to use formatting manipulators


/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  The function initiailizes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
			  into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
			  double_size is called, which doubles the capacity of pop_DB.

**********************************************************************************************************************************************************/

state_class::state_class()
{
	//intially count, capacity, and pop_DB are initialized with the following values:
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];
	//opens ifstream to bring data into program from text file
	ifstream infile;
	infile.open("census2020_data.txt");
	//notifies user if text fail won't open
	if (infile.fail())
	{
		cout << "failed to open census2020_data.txt file";
		exit(1);
	}

	string line;
	//while loop that reads in every line from a text file until the end of the file is reached 
	while (!infile.eof())
	{
		getline(infile, line);
		int numbers = 0;
		int line_length = line.length(); //assigns variable the value of line length

		if (Is_Full())
			double_size();
		// for loop that counts number of digits in state populations
		for (int i = 0; i < line_length; i++) 
		{
			if (isdigit(line[i]))
			numbers++;// stores digit count of state population
		}

		int state_length = (line_length - numbers) - 1; //calculates length of state name
		//assigns state names to pop_DB array object
		pop_DB[count].state_name = line.substr(0, state_length);
		//assigns state populations to pop_DB array objects
		pop_DB[count].population = stod(line.substr((state_length + 1), numbers));
		//increments state count per loop/ line read from text file
		count++;
	}
	infile.close();
}

/******************************************************************************************************************************************************
Name: Copy Constructor
Pre-Condition: State_class is constructed with class population record pop_DB object data
Post-Condition A copy of the state_class is formed
Description: allocates memory for a class copy and pop._DB  object data
******************************************************************************************************************************************************/
state_class::state_class(const state_class & org)
{
	count = org.count; //assigns count to org count
	capacity = org.capacity; //assigns capacity to org capacity
	pop_DB = new population_record[capacity]; //allocates memory for pop_DB new population record
	//loop assigns org objects to pop_DB
	for (int i = 0; i < count; i++)
	{
		pop_DB[i] = org.pop_DB[i];
	}
}

/******************************************************************************************************************************************************
Name: Destructor
Pre-Condition: pop_Db array is an object assigned state names and populations
Post-Condition automatically deletes assigned values when pop_DB goes out of scope
Description: BRIEF DESCRIPTION OF WHAT THE FUNCTION DOES...
******************************************************************************************************************************************************/
state_class::~state_class()
{
	delete[] pop_DB; //deletes pop_DB data that is out of scope
}

/******************************************************************************************************************************************************
Name: void member function double_size
Pre-Condition: capacity is assigned the value of 5
Post-Condition: the capcity is doubled from its previous value before the function call
Description: stores pop_DB objects in temp array then assigns temp array value to pop_DB with increased capacity  
******************************************************************************************************************************************************/
void state_class::double_size()
{		
		//doubles capacity
		capacity *= 2;
		//allocates temporary memory to store pop_DB object
		population_record* temp = new population_record[capacity];
		//loop copies pop_DB objects data to temporary memory
		for (int i = 0; i < count; i++)
		{
			temp[i] = pop_DB[i];
		}
		delete[] pop_DB; //pop_DB data deleted
		pop_DB = temp; // pop_DB with adjusted capacity is reassigned object data from temp memory
}

/******************************************************************************************************************************************************
Name: void constant member function Operator+
Pre-Condition: pop_DB has 52 states and populations assigned to the object arrays
Post-Condition: additional states and their populations are added to the pop_DB arrays
Description: tests capacity, doubles capacity size  if necessary, increments count, adds additional states and their populations to pop_DB
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	if (Is_Full())
		double_size();

	pop_DB[count] = r; // new states and population records are added as pop_DB object
	count++;
}

/******************************************************************************************************************************************************
Name: int constant member function Search
Pre-Condition: state names are all stored in pop_DB object arrays
Post-Condition: state name searched for is found or not found within the pop_DB object arrays
Description: if state is found the index of the state is returned, if not found -1 is returned
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{	
	//loop searching for a state that returns the pop_DB index value if state is found
	for (int i = 0; i < count; i++)
	{
		if (state == pop_DB[i].state_name)
			return i;
	}
	return -1; //returns -1 if state is not found
}


/******************************************************************************************************************************************************
Name: void constant member function Remove
Pre-Condition: all states and populations are stored in pop_DB array indeces
Post-Condition: the state identified is removed from the pop_DB array which is reorganized
Description: the state being removed index is located, and all the states with greater indeces shift down 1 index
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	int i = Search(state); //state pop_DB index or -1 from search is assigned to i
	if (i != -1) //if state was found in search function we proceed to loop
	{
		//loop that overwrites state to be removed by shifting all greater indeces down by 1 
		for (int n = i; n < count - 1; n++)
		{
			pop_DB[n] = pop_DB[n + 1];
		}
		count--;
	}
}


/******************************************************************************************************************************************************
Name: void constant member function Print_ALL_To_File
Pre-Condition: a list of states and their populations are stored in pop_DB objects
Post-Condition: The pop_DB states and populations are copied to a text file in a neat manner
Description: a text file input argument is opened, pop_DB data is made presentable, then copied to the text file, text file is closed
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{	
	// opens text file to store states and populations
	ofstream outfile; 
	outfile.open(filename);
	outfile.setf(ios::fixed); // ofstream fixed numeric notation (avoiding scientific)
	outfile.precision(0); // ofstream numbers decimal points set to 0  
	//loop storing each state and population to ofstream text file
	for (int i = 0; i < count; i++)
	{
		outfile << left << setw(20) << pop_DB[i].state_name << right << setw(15) << pop_DB[i].population << endl;
	}
	outfile << endl;
	outfile.close();
}
/******************************************************************************************************************************************************
Name: void function Print_ALL
Pre-Condition: states and populations are stored in pop_DB
Post-Condition: states and populations are neatly displayed to the screen
Description: pop_DB states and populations displayed, cout notation is fixed, precision set to 0, left/ or right justified, width set 
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
	cout.setf(ios::fixed);
	cout.precision(0);
	//loop displaying all states and populations from pop_DB object
	for (int i = 0; i < count; i++)
	{
		cout << left << setw(20) << pop_DB[i].state_name << right << setw(15) << pop_DB[i].population << endl;
	}
}


/******************************************************************************************************************************************************
Name: void constant member function Print_Range
Pre-Condition: states and populations are stored in pop_DB objects
Post-Condition: states with populations within a particular range are displayed 
Description: neatly displays states and their populations if they are in the range of 500,000 - 1,500,000
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	cout.setf(ios::fixed);
	cout.precision(0);
	//loop displays states and populations of states with 500,000 - 1,500,000 population range
	for (int i = 0; i < count; i++)
	{
		if (pop_DB[i].population >= min && pop_DB[i].population <= max)
		{
			cout << left << setw(20) << pop_DB[i].state_name << right << setw(15) << pop_DB[i].population << endl;
		}
	}
	cout << endl;
}


/******************************************************************************************************************************************************
Name: int constant member function State_Count
Pre-Condition: states and populations are stored in pop_DB objects
Post-Condition: number of states within a particular population range are displayed to screen  
Description: the number of states with populations 500,000 - 1,500,000 is returned
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
	int num_of_states = 0;
	// loop counts the number of states with populations ranging 500,000 - 1,500,000 to be returned
	for (int i = 0; i < count; i++)
	{
		if (pop_DB[i].population >= min && pop_DB[i].population <= max)
		{
			num_of_states++;
		}
	}
	return num_of_states;
}

/******************************************************************************************************************************************************
Name: void member function Sort
Pre-Condition: state names stored in pop_DB are not in any particular order
Post-Condition: state names are stored in alphabetic order in pop_DB
Description: insertion sort algorithm is used to organize states alphabetically within pop_DB 
******************************************************************************************************************************************************/
void state_class::Sort()
{
	population_record key; // creates a temp storage for pop_DB index comparisons
	int n;
	//parent loop assigns key (temporary) state name pop_DB index to pop_DB with a lower index
	for (int i = 1; i < count; i++)
	{
		key = pop_DB[i];
		n = i - 1;
		//nested loop decrements pop_DB[n] index while incrementing pop_DB index values until an index with a lower value then key is found
		while ((n >= 0) && (pop_DB[n].state_name > key.state_name))//loop condition if lower indexed pop_DB is greater then higher indexed key
		{
			pop_DB[n + 1] = pop_DB[n]; // shifts pop_DB state name up one index from n value
			n -= 1;
		}
		pop_DB[n + 1] = key; // inserts key state name in proper order  
	}
}
