//Marc Hebert
//260574038?

directory d;
int dirIterIndx = 0; 
int numEntry = 0;

void d_setDir(directory tmp)
{
	d = tmp;
}

directory d_getDir()
{
	return d;
}

void d_initDir()
{
	int x;
	for(x = 0; x<MAX_FILES; x++)//initialize all slots to empty
	{
		d.list[x].active = 0;
	}
	dirIterIndx = 0; //current directory index (necessary for GetNextFileName() )
}

int d_addEntry(int id, char* name)
{
	if(numEntry >= MAX_FILES)// too many files?
	{
		return -1;
	}
	//else add as
	d.list[numEntry].active = 1;
	d.list[numEntry].inode = id;
	strcpy(d.list[numEntry].fname, name);
	numEntry++;
	return 0;
}	


void resetDirIter()
{
	dirIterIndx = 0;
}
//returns index of file
int d_getNextDirName(char* namebuf)
{
	int rtn = 0;
	if(dirIterIndx >= MAX_FILES)
	{
		resetDirIter();
		rtn = -1;
		namebuf = null;
	}
	else if(d.list[dirIterIndx].active ==1)
	{
		rtn =  dirIterIndx;
		strcpy(namebuf, d.list[dirIterIndx].fname);
		dirIterIndx++;
	}
	else
	{
		resetDirIter();
		rtn =  -1;
		namebuf = null;
	}
	return rtn;
}

int d_name2Index(char* namebuf)
{
	char* tmp;
	int inx =-1;
	resetDirIter();
	while(inx=getNextDirName(tmp) != -1)
	{
		if (strcmp(tmp,namebuf)==0)
		{
			break;
		}
	}
	return inx;
}

int d_getActive(int index)
{
	return d.list[index].active;
}


int d_getInode(int index)
{
	return d.list[index].inode;
}

char* d_getName(int index)
{
	return d.list[index].fname;
}

int d_removeEntry(int index)
{
	if(d_getActive(index) == 0)
			return -1;
	int x;
	for(x = index; x<numEntry;x++)
	{
		if(d_getActive(x+1) == 0)
		{
			d.list[x].active = 0;
			break;
		}
		else
		{
			strcpy(d.list[x].fname,d_getName(x+1));
			d.list[x].inode = d_getInode(x+1);
		}
	}
	return 0;
}
