
static struct i2c_driver fl_driver = {
	.driver = {
		.name = "fl_sensor",
		.pm = &fl_pm_ops,
		.of_match_table = fl_of_match,
	},
	.probe_new = fl_probe,
	.remove = fl_remove,
};

module_i2c_driver(fl_driver)

MODULE_AUTHOR("LIZHE");
MODULE_LICENSE("GPL");
