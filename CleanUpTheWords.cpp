#include <iostream>
#include <fstream>

using namespace std;

/*
 * Function Name:	CleanTheString
 * Description:		Remove non-alpha characters from string and replace with a single space
 */
string CleanTheString(string data)
{
	string cleanData;
	
	cleanData.resize(data.size());
	
	unsigned int cleanDataIndex = 0;
	
	bool hasSpace = true;
	
	for(unsigned int index = 0; index < data.size(); ++index)
	{
		if(isalpha(data[index]) == false)
		{
			// only insert a single space if multiple non-alpha characters are strung together
			if(hasSpace == false)
			{
				cleanData[cleanDataIndex] = ' ';
				hasSpace = true;
				
				++cleanDataIndex;
			}
		}
		else
		{
			cleanData[cleanDataIndex] = tolower(data[index]);
			hasSpace = false;
			++cleanDataIndex;
		}
	}
	
	cleanData.resize(cleanDataIndex);
	
	return cleanData;
}

int main(int argc, char *argv[])
{
	ifstream inputFile(argv[1]);
	// a single line of text from input file
	string data;
	
	// a single line of text from input file without extra symbols
	string cleanData;
	if(inputFile.is_open())
	{
		while(getline(inputFile,data))
		{	
			cleanData = CleanTheString(data);
				
			cout << cleanData << endl;

		}
	}
	else
	{
		cout << "Check input file" << endl;
	}
	
	return 0;
}