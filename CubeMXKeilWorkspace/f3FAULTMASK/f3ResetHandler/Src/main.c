
extern void SystemInit(void);
extern int __main(void);

void ResetHandler();

int main()
{
	
	ResetHandler();
	
}

void ResetHandler()
{
	SystemInit();
	__main();
}