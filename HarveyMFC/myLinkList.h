#pragma once
#include "stdafx.h"
#include "afxdialogex.h"
#include "resource.h"
#include "myLinkList.h"
#include <stdio.h> 
#include <strstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

class Entry {
public:
	CString stock{};
	int quantity{};
	CString desc{};
	double price{ 0.00};

};
class NODE
{
public:
	Entry inv;
	NODE* nextItem;
};

class LinkList
{

private:

	NODE* head; // First item in the list
	NODE *tail; // Last item in the list
	NODE *searchN;

public:
	CString name="";
	int quan{};
	LinkList()
	{
		head = NULL;
		tail = NULL;
	}

	// Add an item to the end of the list
	void push(NODE *value)
	{

		// First, make sure that the nextItem property of the new item is NULL
		// This because the new item will be the last item in the list
		value->nextItem = NULL;

		// If the list is empty
		// Then the item becomes both the first and the last item in the list
		if (head == NULL)
		{
			head = value;
			tail = value;
		}
		else
		{
			// The new item becomes the next item of the current tail
			tail->nextItem = value;

			// The new item then becomes the new tail
			tail = value;
		}
	}

	void push(NODE *value,int q)
	{
		value->inv.quantity = q;
		// First, make sure that the nextItem property of the new item is NULL
		// This because the new item will be the last item in the list
		value->nextItem = NULL;

		// If the list is empty
		// Then the item becomes both the first and the last item in the list
		if (head == NULL)
		{
			head = value;
			tail = value;
		}
		else
		{
			// The new item becomes the next item of the current tail
			tail->nextItem = value;

			// The new item then becomes the new tail
			tail = value;
		}
	}

	// Print out all items in the list


	bool search( CString search)
	{
		NODE* current = head; // Initialize current  
		//searchN = head;
		while (current != nullptr)
		{
			if (current->inv.stock == search){
				searchN = current;
				quan = searchN->inv.quantity;
				name = search;
				return true;
			}
			current = current->nextItem;
		}
		return false;
	}
	NODE* getNode() {
		
		NODE* temp = new NODE();
		temp->inv.stock = searchN->inv.stock,
		temp->inv.quantity = searchN->inv.quantity;
		temp->inv.desc = searchN->inv.desc;
		temp->inv.price = searchN->inv.price;
		return temp;
		delete temp;
	}


	CString getStock() {
		if (head == NULL)
		{
			cout << "The list is empty." << endl;
			return "There is nothing fuck.";
		}
		else
		{
			// Start with the first item
			
			return (name);
		}
	}

	int getQ() {
		if (head == NULL)
		{
			cout << "The list is empty." << endl;
			return -1;
		}
		else
		{
			// Start with the first ite
			return quan;
		}
	}

	//sign TRue for positive, false to negative;
	void setQuantity(int q,BOOL sign) {
		if(sign)
		searchN->inv.quantity += q;
		else
		searchN->inv.quantity -= q;
	}

   
	//
	void print(ostrstream &ostr, BOOL iscustomer, BOOL check)
	{
		if (head == NULL)
		{
			if (iscustomer)
			ostr << "Your cart is empty." << endl;
		}
		else
		{
			// Start with the first item
			NODE* currentItem = head;
			if (!iscustomer)
				ostr << "Store Storage\n\n";
			else
				ostr << "Your Cart !!\n\n";
			ostr  << left << setw(14) << "Stock# " << setw(25) <<  "Quantity" << setw(40) << "Description" << setw(12) << "Price" << endl;
			// As long as there's still one more item to print
			while (currentItem != NULL)
			{
				// Print out the item
				ostr 
					<<left << fixed << setprecision(2)
					<< setw(17) << currentItem->inv.stock  
					<< setw(30) << currentItem->inv.quantity  
					<< currentItem->inv.desc << currentItem->inv.price << endl;

				// Move on to the next item
				currentItem = currentItem->nextItem;
			}
			if(check)
			checkout(ostr);
		}
	}

	void checkout(ostrstream &ostr) {
		double temp{0.00};
	
			// Start with the first item
			NODE* currentItem = head;
			
			// As long as there's still one more item to print
			while (currentItem != NULL)
			{
				// Print out the item

				ostr << "\n\n\n\t\t\t " << currentItem->inv.price;
				if (currentItem->inv.quantity == 1)
					ostr << endl;
				else
					ostr << " x " << currentItem->inv.quantity << endl;

				temp += currentItem->inv.price * currentItem->inv.quantity;
				// Move on to the next item
				currentItem = currentItem->nextItem;
			}
			ostr
				<< "Shipping Handling\t 9.95\n"
				<< "Tax Sale rate\t\t6.25%\n"
				<< "___________________________\n"
				<< "\t\t\t" << (temp*0.625) + 9.95 << endl;

	}

	CString print()
	{
		char s[65353];
		ostrstream ostr(s, 65353);
		CString info;
		char* temp;
		if (head == NULL)
		{
			return "The list is empty.\n";
		}
		else
		{
			// Start with the first item
			NODE* currentItem = head;
			// As long as there's still one more item to print
			while (currentItem != NULL)
			{
				
				ostr << currentItem->inv.stock << " Quantity: " << currentItem->inv.quantity;
				// Move on to the next item
				currentItem = currentItem->nextItem;
			}
			return _T(s);
		}

	}



};