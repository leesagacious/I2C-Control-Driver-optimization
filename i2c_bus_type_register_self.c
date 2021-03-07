
static int __init i2c_self_init(void)
{
	
	/*
	 * Indicates that the I2C bus has been registered
	 * Instead of using a Boolean global variable
	 */
	i2c_bus_type_self.registered++;
	
	return 0;
}	

core_initcall(i2c_self_init);
module_exit(i2c_self_init);
