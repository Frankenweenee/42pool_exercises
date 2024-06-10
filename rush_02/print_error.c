void	print_error(char *msg)
{
	int len = 0;
	while (msg[len]) {
		len++;
	}
    write(1, msg, len);
}