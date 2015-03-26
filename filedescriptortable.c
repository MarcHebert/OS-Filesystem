//Marc Hebert
//260574038

FDT* ft;

void f_init()
{
	int x;
	for(x =0; x<MAX_FILES_;x++)
	{
		ft->f[x].rw = 0;
		ft->f[x].active = 0;
	}

}

void f_activate(int inode)
{
	ft->f[inode].active=1;
}

int f_getRW(int inode)
{
	return ft->f[inode].rw;
}

int f_isActive(int inode)
{
	return ft->f[inode].active;
}

void f_setRW(int inode, int newrw)
{
	ft->f[inode].rw = newrw;
}

void f_incdecRW(int inode, int incdec)
{
	ft->f[inode].rw = f_getRW(inode)+ incdec;
}

void f_deactivate(int inode)
{
	ft->f[inode].active=0;
}
