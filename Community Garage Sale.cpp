// Community Garage Sale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct listing {
	string item;
	bool for_sale;
	int price;
};

int main()
{


	string input_line;
	ifstream f("garageSale.txt");


	if (f.is_open())
	{
		cout << "Items Sold." << endl;
		listing listings_array[100] = {};
		int i = 0;
		while (getline(f, input_line))
		{
			stringstream ss(input_line);
			string item_type, Status, strPrice;
			getline(ss, item_type, ',');
			getline(ss, Status, ',');
			bool for_sale = Status == "for sale";
			getline(ss, strPrice, ',');
			int price = stoi(strPrice);
			//cout << item_type <<" "<< for_sale << " " << price << endl;
			listing incoming_item = { item_type, for_sale, price };
			//Look for partner
			//If found
				//Print item and sale price
				//Delete Partner item
				//continue to read next item
			//If not found
				//Add to list
			bool sold = false;
			for (int x = 0; x < i; x++) {
				listing array_item = listings_array[x];
				if (array_item.item == incoming_item.item) {
					if (array_item.for_sale && !incoming_item.for_sale) {
						if (array_item.price <= incoming_item.price) {
							cout << array_item.item << " " << array_item.price << endl;
							for (int n = x; n < i - 1; n++) {
								listings_array[n] = listings_array[n + 1];
							}
							i = i - 1;
							sold = true;
							break;
						}

					}

					else if (!array_item.for_sale && incoming_item.for_sale) {
						if (array_item.price >= incoming_item.price) {
							for (int n = x; n < i - 1; n++) {
								listings_array[n] = listings_array[n + 1];

							}
							i = i - 1;
							sold = true;
							break;
						}
					}

				}
			}
			if (!sold) {
				//no partner add to array
				listings_array[i] = incoming_item;

				i++;
			}
		}



		f.close();
		//print whats left in array 
		cout << "Items remaining in the message board after reading all lines in the file. " << endl;
		for (int x = 0; x < i; x++) {
			listing array_item = listings_array[x];
			cout << array_item.item << " ";
			if (array_item.for_sale)
				cout << "for sale " << array_item.price << endl;
			else
				cout << "wanted " << array_item.price << endl;
		}
	}
	else
	{
		cout << "File was not opened!" << endl;
	};


}

