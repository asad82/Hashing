/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website				 : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

# include <iostream.h>
# include <conio.h>
# include <ctype.h>
# define PAGE 4

/*                   READ   ME                 */
// Enter The Number In the Usual manner they would be converted
// to binary by the program itself and saved. At any stage you can
// get a view of the numbers using option 2. The Actual Implementation
// Behind is that Of Binary Trees. The page size can also be changed
// according to the user requirement before run time at the top using
// the variable PAGE. Set This Acording To Your Need.

int count = 0, increase = 0;
int down = 0, down1 = 0;
int tempdata[PAGE], tempbinary[PAGE][20], tempcounter[PAGE];
int functiononecount1 = 0, functiononecount = 0, functiononecount11 = 0, functiononecount12 = 0, done = 0;

struct dynamic
{
	int index;
	int counter[PAGE];
	int data[PAGE];
	dynamic *one, *zero;
	int binary[PAGE][20];
};

dynamic *newdynamic, *troot;
int bin[20];
int cd = 0;
/////////////////////////////////////////////////////////////////////


int finddepth(dynamic *ld)
{
	if (ld == NULL)
	{
		return cd;
	}

	if (ld->one != NULL)
	{
		cd++;
		int jk = finddepth(ld->one);
	}

	else if (ld->zero != NULL)
	{
		cd++; int yu = finddepth(ld->zero);
	}

	return cd;


}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void insertone(dynamic *onef, int increase, int actual)
{

	if (bin[increase] == 1)// && increase<=(down+1))
	{
		cout << "1";
		if (onef->one == NULL && onef->one != troot && (onef->index == 0 || onef->index == PAGE) && functiononecount == 0)
		{
			int temporary = 0;
			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (int o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			for (int y = count - 1; y > -1; y--)
			{
				newdynamic->binary[newdynamic->index][temporary++] = bin[y];
			}
			newdynamic->counter[newdynamic->index] = (temporary - 1);
			newdynamic->data[newdynamic->index] = actual;
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			newdynamic->index++;
			onef->one = newdynamic;
			cout << "\n Value Inserted Only Once(one) (Newnode Created).";
			functiononecount++;            done++;   return;
		}
		///////////////////////////////////////////////////////////////////////////////

		if (onef->one == NULL && onef->one != troot &&  onef->index == PAGE && functiononecount == 1 && done == 0)
		{
			int temporary = 0;

			for (int y = 0; y < onef->index; y++)
			{  //tempindex[y]=onef->index;
				tempcounter[y] = onef->counter[y];
				for (int k = 0; k <= onef->counter[y]; k++)
				{
					tempbinary[y][k] = onef->binary[y][k];
				}
				tempdata[y] = onef->data[y];
			}

			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (int o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			onef->one = newdynamic;
			//cout << "\n Value Inserted ( Newnode Created).";
			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			onef->zero = newdynamic;
			cout << "\n Value Inserted ( Newnode Created).";
			// increase+=1;// depth level increased by 1

			///// now for 0 to be inserted again.
			for (int u = 0; u < PAGE; u++)
			{
				temporary = 0;
				if (tempbinary[u][(tempcounter[u] - increase)] == 0)
				{
					for (int y = 0; y <= tempcounter[u]; y++)
					{
						newdynamic->binary[newdynamic->index][y] = tempbinary[u][y];
					}
					newdynamic->counter[newdynamic->index] = tempcounter[u];
					newdynamic->data[newdynamic->index] = tempdata[u];
					newdynamic->index++;
				}
			}

			///// now for 1 to be inserted again.
			onef->index = 0;   // index of previous node set to 0 to delete data.
			dynamic *save = onef;
			onef = onef->one;    // now switching to left side (left Newnode).
			for (u = 0; u < PAGE; u++)
			{
				temporary = 0;
				if (tempbinary[u][(tempcounter[u] - increase)] == 1)
				{
					for (int y = 0; y <= tempcounter[u]; y++)
					{
						onef->binary[onef->index][y] = tempbinary[u][y];
					}
					onef->counter[onef->index] = tempcounter[u];
					onef->data[onef->index] = tempdata[u];
					onef->index++;
				}
			}
			/////////now to insert the actual present value after adjusting previous values.
			//onef=save;
			// onef=onef->zero;

			if (bin[(increase + 1)] == 0 && onef->index != (PAGE + 1))
			{  // onef=save;
				//onef=onef->zero;
				for (int y = count - 1; y > -1; y--)
				{
					onef->binary[onef->index][temporary++] = bin[y];
				}
				onef->counter[onef->index] = (temporary - 1);
				onef->data[onef->index] = actual;
				onef->index++;
			}

			onef = save;
			onef = onef->one;

			if (bin[(increase + 1)] == 1 && onef->index != (PAGE + 1))
			{     // onef=save;
				//  onef=onef->one;
				for (int y = count - 1; y > -1; y--)
				{
					onef->binary[onef->index][temporary++] = bin[y];
				}
				onef->counter[onef->index] = (temporary - 1);
				onef->data[onef->index] = actual;
				onef->index++;
			}   done++;
			cout << "\n Split One.";

		}



		///////////////////////////////////////////////////////////////////////////////



		else if (onef->one == NULL && onef->index != 0 && onef->index <= PAGE && done == 0)
		{
			int temporary = 0;
			for (int y = count - 1; y > -1; y--)
			{
				onef->binary[onef->index][temporary++] = bin[y];
			}
			onef->counter[onef->index] = (temporary - 1);
			onef->data[onef->index] = actual;
			onef->one = NULL;
			onef->zero = NULL;
			onef->index++;
			cout << "\n Value Inserted.(Only Inserts Value)(one)";  done++;
		}

		else
		{
			increase++; insertone(onef->one, increase, actual);
		}

	}


	else if (bin[increase] == 0)// && increase<=(down+1))
	{
		cout << "0";
		/*  if(onef->zero==NULL && (onef->index==0 || onef->index==PAGE) && functiononecount1==0 && done==0)
				   {   int temporary=0;
				   newdynamic=new dynamic;
				   newdynamic->index=0;
				   for(int o=0;o<PAGE;o++)
				   {
				   newdynamic->counter[o]=0;
				   newdynamic->data[o]=0;}
				   for(int y=count-1;y>-1;y--)
				   { newdynamic->binary[newdynamic->index][temporary++]=bin[y];}
				   newdynamic->counter[newdynamic->index]=(temporary-1);
				   newdynamic->data[newdynamic->index]=actual;
				   newdynamic->one=NULL;
				   newdynamic->zero=NULL;
				   newdynamic->index++;
				   onef->zero=newdynamic;
				   cout<<"\n Value Inserted Only Once Zero (Newnode Created).";
				   functiononecount1++;                 done++;     return;
				   }    */

		///////////////////////////////////////////////////////////////////////////////

		if (onef->one == NULL && onef->one != troot &&  onef->index == PAGE && functiononecount1 == 0 && done == 0)
		{
			int temporary = 0;

			for (int y = 0; y < onef->index; y++)
			{  //tempindex[y]=onef->index;
				tempcounter[y] = onef->counter[y];
				for (int k = 0; k <= onef->counter[y]; k++)
				{
					tempbinary[y][k] = onef->binary[y][k];
				}
				tempdata[y] = onef->data[y];
			}

			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (int o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			onef->one = newdynamic;
			//cout << "\n Value Inserted ( Newnode Created).";
			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			onef->zero = newdynamic;
			cout << "\n Value Inserted ( Newnode Created).";
			// increase+=1;// depth level increased by 1

			///// now for 0 to be inserted again.
			for (int u = 0; u < PAGE; u++)
			{
				temporary = 0;
				if (tempbinary[u][(tempcounter[u] - increase)] == 0)
				{
					for (int y = 0; y <= tempcounter[u]; y++)
					{
						newdynamic->binary[newdynamic->index][y] = tempbinary[u][y];
					}
					newdynamic->counter[newdynamic->index] = tempcounter[u];
					newdynamic->data[newdynamic->index] = tempdata[u];
					newdynamic->index++;
				}
			}

			///// now for 1 to be inserted again.
			onef->index = 0;   // index of previous node set to 0 to delete data.
			dynamic *save;
			save = onef;
			onef = onef->one;    // now switching to left side (left Newnode).
			for (u = 0; u < PAGE; u++)
			{
				temporary = 0;
				if (tempbinary[u][(tempcounter[u] - increase)] == 1)
				{
					for (int y = 0; y <= tempcounter[u]; y++)
					{
						onef->binary[onef->index][y] = tempbinary[u][y];
					}
					onef->counter[onef->index] = tempcounter[u];
					onef->data[onef->index] = tempdata[u];
					onef->index++;
				}
			}

			/////////now to insert the actual present value after adjusting previous values.
			onef = save;
			onef = onef->zero;
			int under = (increase);
			cout << "\n Increase=" << increase;
			cout << "\n Bin[Under]=" << bin[under];
			if (bin[under] == 0 && onef->index != (PAGE + 1))
			{   //onef=save;
				//onef=onef->zero;
				for (int y = count - 1; y > -1; y--)
				{
					onef->binary[onef->index][temporary++] = bin[y];
				}
				onef->counter[onef->index] = (temporary - 1);
				onef->data[onef->index] = actual;
				onef->index++;  cout << "\nActual 1.";
			}

			onef = save;
			onef = onef->one;

			if (bin[under] == 1 && onef->index != (PAGE + 1))
			{      //onef=save;
				// onef=onef->one;
				for (int y = count - 1; y > -1; y--)
				{
					onef->binary[onef->index][temporary++] = bin[y];
				}
				onef->counter[onef->index] = (temporary - 1);
				onef->data[onef->index] = actual;
				onef->index++;  cout << "\nActual 2.";
			}         done++;

			cout << "\n Split Zero.";
		}



		///////////////////////////////////////////////////////////////////////////////


		else if (onef->zero == NULL && onef->index != 0 && onef->index <= PAGE && done == 0)
		{
			int temporary = 0;
			for (int y = count - 1; y > -1; y--)
			{
				onef->binary[onef->index][temporary++] = bin[y];
			}
			onef->counter[onef->index] = (temporary - 1);
			onef->data[onef->index] = actual;
			onef->one = NULL;
			onef->zero = NULL;
			onef->index++;
			cout << "\n Value Inserted (Only Inserts Value)(Zero)."; done++;
		}

		else
		{
			increase++; insertone(onef->zero, increase, actual);
		}

	}

}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void insertzero(dynamic *oner, int increase, int actual)
{
	////////////////////
	if (bin[increase] == 1)// && increase<=(down+1))
	{
		cout << "1";
		/* if(oner->one==NULL && oner->one!=troot && (oner->index==0 || oner->index==PAGE) && functiononecount12==0)
				  {  int temporary=0;
				  newdynamic=new dynamic;
				  newdynamic->index=0;
				  for(int o=0;o<PAGE;o++)
				  {
				  newdynamic->counter[o]=0;
				  newdynamic->data[o]=0;}
				  for(int y=count-1;y>-1;y--)
				  { newdynamic->binary[newdynamic->index][temporary++]=bin[y];}
				  newdynamic->counter[newdynamic->index]=(temporary-1);
				  newdynamic->data[newdynamic->index]=actual;
				  newdynamic->one=NULL;
				  newdynamic->zero=NULL;
				  newdynamic->index++;
				  oner->one=newdynamic;
				  cout<<"\n Value Inserted Only Once(one) (Newnode Created).";
				  functiononecount++;            done++;   return;
				  }    */
		///////////////////////////////////////////////////////////////////////////////

		if (oner->zero == NULL && oner->zero != troot &&  oner->index == PAGE && functiononecount12 == 0 && done == 0)
		{
			int temporary = 0;

			for (int y = 0; y < oner->index; y++)
			{  //tempindex[y]=oner->index;
				tempcounter[y] = oner->counter[y];
				for (int k = 0; k <= oner->counter[y]; k++)
				{
					tempbinary[y][k] = oner->binary[y][k];
				}
				tempdata[y] = oner->data[y];
			}

			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (int o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			oner->one = newdynamic;
			//cout << "\n Value Inserted ( Newnode Created).";
			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			oner->zero = newdynamic;
			cout << "\n Value Inserted ( Newnode Created).";
			// increase+=1;// depth level increased by 1

			///// now for 0 to be inserted again.
			for (int u = 0; u < PAGE; u++)
			{
				temporary = 0;
				if (tempbinary[u][(tempcounter[u] - increase)] == 0)
				{
					for (int y = 0; y <= tempcounter[u]; y++)
					{
						newdynamic->binary[newdynamic->index][y] = tempbinary[u][y];
					}
					newdynamic->counter[newdynamic->index] = tempcounter[u];
					newdynamic->data[newdynamic->index] = tempdata[u];
					newdynamic->index++;
				}
			}

			///// now for 1 to be inserted again.
			oner->index = 0;   // index of previous node set to 0 to delete data.
			dynamic *save = oner;
			oner = oner->one;    // now switching to left side (left Newnode).
			for (u = 0; u < PAGE; u++)
			{
				temporary = 0;
				if (tempbinary[u][(tempcounter[u] - increase)] == 1)
				{
					for (int y = 0; y <= tempcounter[u]; y++)
					{
						oner->binary[oner->index][y] = tempbinary[u][y];
					}
					oner->counter[oner->index] = tempcounter[u];
					oner->data[oner->index] = tempdata[u];
					oner->index++;
				}
			}
			/////////now to insert the actual present value after adjusting previous values.
			//oner=save;
			// oner=oner->zero;

			if (bin[(increase + 1)] == 0 && oner->index != (PAGE + 1))
			{  // oner=save;
				//oner=oner->zero;
				for (int y = count - 1; y > -1; y--)
				{
					oner->binary[oner->index][temporary++] = bin[y];
				}
				oner->counter[oner->index] = (temporary - 1);
				oner->data[oner->index] = actual;
				oner->index++;
			}

			oner = save;
			oner = oner->one;

			if (bin[(increase + 1)] == 1 && oner->index != (PAGE + 1))
			{     // oner=save;
				//  oner=oner->one;
				for (int y = count - 1; y > -1; y--)
				{
					oner->binary[oner->index][temporary++] = bin[y];
				}
				oner->counter[oner->index] = (temporary - 1);
				oner->data[oner->index] = actual;
				oner->index++;
			}   done++;
			cout << "\n Split One.";

		}



		///////////////////////////////////////////////////////////////////////////////



		else if (oner->zero == NULL && oner->index != 0 && oner->index <= PAGE && done == 0)
		{
			int temporary = 0;
			for (int y = count - 1; y > -1; y--)
			{
				oner->binary[oner->index][temporary++] = bin[y];
			}
			oner->counter[oner->index] = (temporary - 1);
			oner->data[oner->index] = actual;
			oner->one = NULL;
			oner->zero = NULL;
			oner->index++;
			cout << "\n Value Inserted.(Only Inserts Value)(one)";  done++;
		}

		else
		{
			increase++; insertzero(oner->one, increase, actual);
		}

	}


	else if (bin[increase] == 0)// && increase<=(down+1))
	{
		cout << "0";
		if (oner->zero == NULL && (oner->index == 0 || oner->index == PAGE) && functiononecount11 == 0 && done == 0)
		{
			int temporary = 0;
			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (int o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			for (int y = count - 1; y > -1; y--)
			{
				newdynamic->binary[newdynamic->index][temporary++] = bin[y];
			}
			newdynamic->counter[newdynamic->index] = (temporary - 1);
			newdynamic->data[newdynamic->index] = actual;
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			newdynamic->index++;
			oner->zero = newdynamic;
			cout << "\n Value Inserted Only Once Zero (Newnode Created).";
			functiononecount11++;                 done++;     return;
		}

		///////////////////////////////////////////////////////////////////////////////

		if (oner->zero == NULL && oner->zero != troot &&  oner->index == PAGE && functiononecount11 == 1 && done == 0)
		{
			int temporary = 0;

			for (int y = 0; y < oner->index; y++)
			{  //tempindex[y]=oner->index;
				tempcounter[y] = oner->counter[y];
				for (int k = 0; k <= oner->counter[y]; k++)
				{
					tempbinary[y][k] = oner->binary[y][k];
				}
				tempdata[y] = oner->data[y];
			}

			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (int o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			oner->one = newdynamic;
			//cout << "\n Value Inserted ( Newnode Created).";
			newdynamic = new dynamic;
			newdynamic->index = 0;
			for (o = 0; o < PAGE; o++)
			{
				newdynamic->counter[o] = 0;
				newdynamic->data[o] = 0;
			}
			newdynamic->one = NULL;
			newdynamic->zero = NULL;
			oner->zero = newdynamic;
			cout << "\n Value Inserted ( Newnode Created).";
			// increase+=1;// depth level increased by 1

			///// now for 0 to be inserted again.
			for (int u = 0; u < PAGE; u++)
			{
				temporary = 0;
				if (tempbinary[u][(tempcounter[u] - increase)] == 0)
				{
					for (int y = 0; y <= tempcounter[u]; y++)
					{
						newdynamic->binary[newdynamic->index][y] = tempbinary[u][y];
					}
					newdynamic->counter[newdynamic->index] = tempcounter[u];
					newdynamic->data[newdynamic->index] = tempdata[u];
					newdynamic->index++;
				}
			}

			///// now for 1 to be inserted again.
			oner->index = 0;   // index of previous node set to 0 to delete data.
			dynamic *save;
			save = oner;
			oner = oner->one;    // now switching to left side (left Newnode).
			for (u = 0; u < PAGE; u++)
			{
				temporary = 0;
				if (tempbinary[u][(tempcounter[u] - increase)] == 1)
				{
					for (int y = 0; y <= tempcounter[u]; y++)
					{
						oner->binary[oner->index][y] = tempbinary[u][y];
					}
					oner->counter[oner->index] = tempcounter[u];
					oner->data[oner->index] = tempdata[u];
					oner->index++;
				}
			}

			/////////now to insert the actual present value after adjusting previous values.
			oner = save;
			oner = oner->zero;
			int under = (increase);
			cout << "\n Increase=" << increase;
			cout << "\n Bin[Under]=" << bin[under];
			if (bin[under] == 0 && oner->index != (PAGE + 1))
			{   //oner=save;
				//oner=oner->zero;
				for (int y = count - 1; y > -1; y--)
				{
					oner->binary[oner->index][temporary++] = bin[y];
				}
				oner->counter[oner->index] = (temporary - 1);
				oner->data[oner->index] = actual;
				oner->index++;  cout << "\nActual 1.";
			}

			oner = save;
			oner = oner->one;

			if (bin[under] == 1 && oner->index != (PAGE + 1))
			{      //oner=save;
				// oner=oner->one;
				for (int y = count - 1; y > -1; y--)
				{
					oner->binary[oner->index][temporary++] = bin[y];
				}
				oner->counter[oner->index] = (temporary - 1);
				oner->data[oner->index] = actual;
				oner->index++;  cout << "\nActual 2.";
			}         done++;

			cout << "\n Split Zero.";
		}



		///////////////////////////////////////////////////////////////////////////////


		else if (oner->zero == NULL && oner->index != 0 && oner->index <= PAGE && done == 0)
		{
			int temporary = 0;
			for (int y = count - 1; y > -1; y--)
			{
				oner->binary[oner->index][temporary++] = bin[y];
			}
			oner->counter[oner->index] = (temporary - 1);
			oner->data[oner->index] = actual;
			oner->one = NULL;
			oner->zero = NULL;
			oner->index++;
			cout << "\n Value Inserted (Only Inserts Value)(Zero)."; done++;
		}

		else
		{
			increase++; insertzero(oner->zero, increase, actual);
		}

	}


	////////////////////
}




/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
void preorder(dynamic *root)
{
	dynamic* troot = root;
	if (root != NULL)
	{
		for (int y = 0; y < root->index; y++)
		{
			for (int k = 0; k <= root->counter[y]; k++)
			{
				cout << root->binary[y][k];
			}
			cout << "--(" << root->data[y] << ")\t";
		}
		cout << "\n";
		preorder(root->one);
		cout << "\n";
		preorder(root->zero);

	}
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/*void inorder(dynamic *root)
{
dynamic* troot=root;
if(troot!=NULL)
{
inorder(root->one);
cout<<root->data<<"\n";
inorder(root->zero);
}
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void postorder(dynamic *root)
{
dynamic* troot=root;
if(troot!=NULL)
{
postorder(root->one);
postorder(root->zero);
cout<<root->data<<"\n";

}
}  */
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void main()
{
	clrscr();
	dynamic *root, *newdynamic;
	int info, rem, preserve;
	int choice, rootcount = 0;

	do{
		clrscr();
		cout << "\n Press 1 To Enter Data."
			<< "\n Press 2 For Pre-order Traversal."
			<< "\n Press 0 To Quit.";
		cout << "\n Enter Your Choice=";
		cin >> choice;


		if (choice == 1)
		{
			if (rootcount == 0)
			{
				root = new dynamic;
				root->one = NULL;
				root->index = PAGE;
				for (int o = 0; o < PAGE; o++)
				{
					root->counter[o] = 0;
					root->data[o] = 0;
				}
				root->zero = NULL;
				troot = root;
			}

			count = 0;  increase = 0;
			for (int u = 0; u < 20; u++)
			{
				bin[u] = 0;
			}
			troot = root;
			cout << "\n Enter Data=";
			cin >> info;
			preserve = info;
			while (info != 1)
			{
				rem = info % 2;
				info /= 2;
				bin[count++] = rem;
				//cout<<rem;
			}
			bin[count++] = info;
			for (int g = count - 1; g > -1; g--)
			{
				cout << bin[g];
			}
			//cout<<info;
			info = preserve;
			increase = 0;
			if (bin[0] == 1)
			{
				cd = 0;      done = 0;
				down = finddepth(troot->one);
				cout << "\n Depth One=" << down << "\n Path=";
				//cout<<"1";
				done = 0;
				insertone(troot, increase, info);
			}
			else if (bin[0] == 0)
			{
				cd = 0;         done = 0;
				down1 = finddepth(troot->zero);
				cout << "\n Depth Zero=" << down1 << "\n Path=";
				//cout<<"0";
				insertzero(troot, increase, info);
			}
			rootcount++;
			getch();
		}

		else if (choice == 2)
		{
			clrscr();
			cout << "\n Preorder Traversal Is.\n";
			preorder(troot);   getch();
		}
	} while (choice != 0);
	//getch();
	//cout<<"\n Inorder Traversal Is.\n";
	//inorder(troot);
	//getch();
	//cout<<"\n Postorder Traversal Is.\n";
	//postorder(troot);

}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////