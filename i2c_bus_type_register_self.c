/*
 * The match function is a very beautiful function. 
 * one parameter is device and the other is device driver
 */
static int i2c_device_match(struct device *dev, struct device_driver *drv)
{


	return 0;
}	

struct bus_type i2c_bus_type_self = {
	.name = "self_i2c_lee",
	.match = self_appropriate,
};

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
