BUILD_DIR := build
SAMPLES := $(BUILD_DIR)/cylon $(BUILD_DIR)/blank $(BUILD_DIR)/sensors
LIB := $(BUILD_DIR)/libsense-hat.so

CXXFLAGS := -Isrc -Os
PICFLAGS := -fPIC
SO_LDFLAGS := -shared -rdynamic

all: $(SAMPLES)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/blank: src/blank.cpp src/sense-hat.h $(LIB) $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/blank src/blank.cpp -L$(BUILD_DIR) -lsense-hat

$(BUILD_DIR)/cylon: src/cylon.cpp src/sense-hat.h $(LIB) $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/cylon src/cylon.cpp -L$(BUILD_DIR) -lsense-hat

$(BUILD_DIR)/sensors: src/sensors.cpp src/sense-hat.h $(LIB) $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/sensors src/sensors.cpp -L$(BUILD_DIR) -lsense-hat

$(LIB): src/sense-hat.o $(BUILD_DIR)
	$(CXX) $(SO_LDFLAGS) -o $@ $< -lRTIMULib

src/sense-hat.so: src/sense-hat.cpp src/sense-hat.h
	$(CXX) $(CXXFLAGS) $(PICFLAGS) $(SO_LDFLAGS) -o $@ src/sense-hat.cpp

clean:
	rm -rf $(BUILD_DIR)
	rm src/sense-hat.o
