

static int fl_probe(struct i2c_client *client)
{

	return 0;
}	

static const struct of_device_id fl_of_match[] = {
	/*
	 * contrast  with the node's compatible in dts
	 */
	{ .compatible = "Honeywell,carboncd500",	.data = NULL },
	{ },
};

static const struct i2c_device_id fl_table[] = {
	{ "carboncd500", NULL},
	{ },
};	

static struct i2c_driver fl_driver = {
	.driver = {
		.name = "fl_sensor",
		.pm = &fl_pm_ops,
		.of_match_table = fl_of_match,
	},
	.probe_new = fl_probe,
	.remove = fl_remove,
	/*
	 * It is not limited to the i2c_client of the device tree. 
	 * through user space or other ways
	 */
	.id_table = fl_table,
};

module_i2c_driver(fl_driver)

MODULE_AUTHOR("LIZHE");
MODULE_LICENSE("GPL");
