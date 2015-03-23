struct open_file_table{}typedef OFT;
int make_open_file_table_entry(int nextfile, int inode); 
int find_next_free_slot(OFT table);
OFT createOFT();