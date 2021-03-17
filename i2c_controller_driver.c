#include <linux/platform_device.h>


static int i2c_controller_self_probe(struct platform_device *pdev)
{
	int ret;
	
	return 0;

res_failed:
	
	return ret;	
}

static struct platform_driver i2c_controller_self_driver = {
	.driver		= {
		.name	= "i2c-con_self",
		.of_match_table	= of_match_ptr(i2c_controller_self_dt_ids),
	},
	.remove		= i2c_controller_self_remove,
};


module_platform_driver_probe(&i2c_controller_self_driver, i2c_controller_self_probe);
