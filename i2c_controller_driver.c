#include <linux/platform_device.h>


static int i2c_controller_self_probe(struct platform_device *pdev)
{
	int ret, irq;
	struct resource *res;
	void __iomem *base;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	ret = devm_request_threaded_irq();
	if (ret) {
		dev_err(&pdev->dev, "register irq has failure %d\n", irq);
		goto res_failed;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(base))
		return PTR_ERR(base);
	
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
