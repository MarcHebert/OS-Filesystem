//Marc Hebert
//260574038
 
sblock* s_init()
{
	sblock* s;
	s->magic = SB_MAGIC_;
	s->blocksize = BLOCKSIZE_;
	s->fsSize = NUM_BLOCKS_;
	s->itablelength = NUM_INODES_;
	s->rtdir = 0;/
	return s;
}
