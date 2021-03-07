struct bus_type i2c_bus_type_self {
	struct bus_type base_bus_type;
	int registered;
};
