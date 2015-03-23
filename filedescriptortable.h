struct file_descriptor_table{}typedef FDT;

int find_next_free_slot(FDT table);
int make_file_desc_entry(entry,  oft_entry,  read_pointer,  write_pointer);
FDT createFDT();