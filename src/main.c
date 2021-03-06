/*
 * Copyright (c) 2016 Open-RnD Sp. z o.o.
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <sys/util.h>
#include <sys/printk.h>
#include <inttypes.h>
#include <init.h>
#include <stdio.h>
#include <drivers/sensor.h>



#define SLEEP_TIME_MS	1
int a=1;
int a2=1;
int a3=1;
int number_of_letter=0;
/*
 * Get button configuration from the devicetree sw0 alias.
 *
 * At least a GPIO device and pin number must be provided. The 'flags'
 * cell is optional.
 */

 // SW0

#define SW0_NODE	DT_ALIAS(sw0)

#if DT_NODE_HAS_STATUS(SW0_NODE, okay)
#define SW0_GPIO_LABEL	DT_GPIO_LABEL(SW0_NODE, gpios)
#define SW0_GPIO_PIN	DT_GPIO_PIN(SW0_NODE, gpios)
#define SW0_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW0_NODE, gpios))
#else
#error "Unsupported board: sw0 devicetree alias is not defined"
#define SW0_GPIO_LABEL	""
#define SW0_GPIO_PIN	0
#define SW0_GPIO_FLAGS	0
#endif

//SW1
#define SW1_NODE	DT_ALIAS(sw1)

#if DT_NODE_HAS_STATUS(SW1_NODE, okay)
#define SW1_GPIO_LABEL	DT_GPIO_LABEL(SW1_NODE, gpios)
#define SW1_GPIO_PIN	DT_GPIO_PIN(SW1_NODE, gpios)
#define SW1_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW1_NODE, gpios))
#else
#error "Unsupported board: sw1 devicetree alias is not defined"
#define SW1_GPIO_LABEL	""
#define SW1_GPIO_PIN	0
#define SW1_GPIO_FLAGS	0
#endif

//SW2
#define SW2_NODE	DT_ALIAS(sw2)

#if DT_NODE_HAS_STATUS(SW2_NODE, okay)
#define SW2_GPIO_LABEL	DT_GPIO_LABEL(SW2_NODE, gpios)
#define SW2_GPIO_PIN	DT_GPIO_PIN(SW2_NODE, gpios)
#define SW2_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW2_NODE, gpios))
#else
#error "Unsupported board: SW2 devicetree alias is not defined"
#define SW2_GPIO_LABEL	""
#define SW2_GPIO_PIN	0
#define SW2_GPIO_FLAGS	0
#endif

//SW3
#define SW3_NODE	DT_ALIAS(sw3)

#if DT_NODE_HAS_STATUS(SW3_NODE, okay)
#define SW3_GPIO_LABEL	DT_GPIO_LABEL(SW3_NODE, gpios)
#define SW3_GPIO_PIN	DT_GPIO_PIN(SW3_NODE, gpios)
#define SW3_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW3_NODE, gpios))
#else
#error "Unsupported board: SW3 devicetree alias is not defined"
#define SW3_GPIO_LABEL	""
#define SW3_GPIO_PIN	0
#define SW3_GPIO_FLAGS	0
#endif

//SW4
#define SW4_NODE	DT_ALIAS(sw4)

#if DT_NODE_HAS_STATUS(SW4_NODE, okay)
#define SW4_GPIO_LABEL	DT_GPIO_LABEL(SW4_NODE, gpios)
#define SW4_GPIO_PIN	DT_GPIO_PIN(SW4_NODE, gpios)
#define SW4_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW4_NODE, gpios))
#else
#error "Unsupported board: SW4 devicetree alias is not defined"
#define SW4_GPIO_LABEL	""
#define SW4_GPIO_PIN	0
#define SW4_GPIO_FLAGS	0
#endif

//SW5
#define SW5_NODE	DT_ALIAS(sw5)

#if DT_NODE_HAS_STATUS(SW5_NODE, okay)
#define SW5_GPIO_LABEL	DT_GPIO_LABEL(SW5_NODE, gpios)
#define SW5_GPIO_PIN	DT_GPIO_PIN(SW5_NODE, gpios)
#define SW5_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW5_NODE, gpios))
#else
#error "Unsupported board: SW5 devicetree alias is not defined"
#define SW5_GPIO_LABEL	""
#define SW5_GPIO_PIN	0
#define SW5_GPIO_FLAGS	0
#endif

//SW6
#define SW6_NODE	DT_ALIAS(sw6)

#if DT_NODE_HAS_STATUS(SW6_NODE, okay)
#define SW6_GPIO_LABEL	DT_GPIO_LABEL(SW6_NODE, gpios)
#define SW6_GPIO_PIN	DT_GPIO_PIN(SW6_NODE, gpios)
#define SW6_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW6_NODE, gpios))
#else
#error "Unsupported board: SW6 devicetree alias is not defined"
#define SW6_GPIO_LABEL	""
#define SW6_GPIO_PIN	0
#define SW6_GPIO_FLAGS	0
#endif

//SW7
#define SW7_NODE	DT_ALIAS(sw7)

#if DT_NODE_HAS_STATUS(SW7_NODE, okay)
#define SW7_GPIO_LABEL	DT_GPIO_LABEL(SW7_NODE, gpios)
#define SW7_GPIO_PIN	DT_GPIO_PIN(SW7_NODE, gpios)
#define SW7_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW7_NODE, gpios))
#else
#error "Unsupported board: SW7 devicetree alias is not defined"
#define SW7_GPIO_LABEL	""
#define SW7_GPIO_PIN	0
#define SW7_GPIO_FLAGS	0
#endif

//SW8
#define SW8_NODE	DT_ALIAS(sw8)

#if DT_NODE_HAS_STATUS(SW8_NODE, okay)
#define SW8_GPIO_LABEL	DT_GPIO_LABEL(SW8_NODE, gpios)
#define SW8_GPIO_PIN	DT_GPIO_PIN(SW8_NODE, gpios)
#define SW8_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW8_NODE, gpios))
#else
#error "Unsupported board: SW8 devicetree alias is not defined"
#define SW8_GPIO_LABEL	""
#define SW8_GPIO_PIN	0
#define SW8_GPIO_FLAGS	0
#endif
/* LED helpers, which use the led0 devicetree alias if it's available. LED0*/
static const struct device *initialize_led(void);
static void match_led_to_button(const struct device *button,
				const struct device *led);

/* LED helpers, which use the led1 devicetree alias if it's available. LED1*/
static const struct device *initialize_led2(void);
static void match_led_to_button2(const struct device *button,
				const struct device *led);

/* LED helpers, which use the LED2 devicetree alias if it's available. LED2*/
static const struct device *initialize_led3(void);
static void match_led_to_button3(const struct device *button,
				const struct device *led);
/* LED 3 LED 4*/
static const struct device *initialize_led4(void);
static void match_led_to_button678(const struct device *button, const struct device *button1, const struct device *button2,
				const struct device *led);
static const struct device *initialize_led5(void);
static void match_led_to_button679(const struct device *button, const struct device *button1, const struct device *button2,
				const struct device *led);

static struct gpio_callback button_cb_data;
static struct gpio_callback button2_cb_data;
static struct gpio_callback button3_cb_data;
static struct gpio_callback button4_cb_data;
static struct gpio_callback button5_cb_data;
static struct gpio_callback button6_cb_data;
static struct gpio_callback button7_cb_data;
static struct gpio_callback button8_cb_data;
static struct gpio_callback button9_cb_data;

void button_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("Button released at %" PRIu32 "\n", k_cycle_get_32());
}

void button_pressed2(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("Button2 released at %" PRIu32 "\n", k_cycle_get_32());
}

void button_pressed3(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("Button3 released at %" PRIu32 "\n", k_cycle_get_32());
}
void button_pressed4(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	number_of_letter=number_of_letter+1;
	printk("Number of letter: %d \n",number_of_letter);
}

void button_pressed5(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	number_of_letter=0;
	printk("Your take all letter from mailbox. Number of letter: %d \n",number_of_letter);
}

void button_pressed6(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("The switch to open the roller shutter pushed.\n");
}

void button_pressed7(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("The switch to close the roller shutter pushed.\n");
}

void button_pressed8(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("The blind is opened\n");
}

void button_pressed9(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("The blind is closed.\n");
}


void main(void)
{
	const struct device *button, *button2, *button3, *button4, *button5, *button6, *button7, *button8, *button9;
	const struct device *led, *led2, *led3, *led4, *led5;
	// Nie dziala struct device *dev;
	int ret;

	//Temperature Sensor
	/*dev = device_get_binding("SI7006");

	if (dev == NULL) {
		printk("Could not get SI7006 device\n");
		return;
	}

	printk("device is %p, name is %s\n", dev, dev->name);
	while (1) {
		printf("hello");
		struct sensor_value temp;
		printf("hello");
		struct sensor_value press;
		printf("hello");

		ret = sensor_sample_fetch(dev);
		printf("hello");
		if (ret) {
			printf("sample fetch error %d\n", ret);
			continue;
		}
		printf("hello");
		sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &temp);
		printf("hello");
		sensor_channel_get(dev, SENSOR_CHAN_HUMIDITY, &press);
		printf("hello");

		printf("Temperature: %d.%06d\n", temp.val1,
		      temp.val2);		
		k_sleep(K_MSEC(1000));
	}
	*/
	//Binding button to SW0
	button = device_get_binding(SW0_GPIO_LABEL);
	if (button == NULL) {
		printk("Error: didn't find %s device\n", SW0_GPIO_LABEL);
		return;
	}
	
	//Binding button to SW1
	button2 = device_get_binding(SW1_GPIO_LABEL);
	if (button2 == NULL) {
		printk("Error: didn't find %s device\n", SW1_GPIO_LABEL);
		return;
	}
	//Binding button to SW2
	button3 = device_get_binding(SW2_GPIO_LABEL);
	if (button3 == NULL) {
		printk("Error: didn't find %s device\n", SW2_GPIO_LABEL);
		return;
	}

	//Binding button to SW3
	button4 = device_get_binding(SW3_GPIO_LABEL);
	if (button4 == NULL) {
		printk("Error: didn't find %s device\n", SW3_GPIO_LABEL);
		return;
	}

	//Binding button to SW4
	button5 = device_get_binding(SW4_GPIO_LABEL);
	if (button5 == NULL) {
		printk("Error: didn't find %s device\n", SW4_GPIO_LABEL);
		return;
	}

	//Binding button to SW5
	button6 = device_get_binding(SW5_GPIO_LABEL);
	if (button6 == NULL) {
		printk("Error: didn't find %s device\n", SW5_GPIO_LABEL);
		return;
	}

	//Binding button to SW6
	button7 = device_get_binding(SW6_GPIO_LABEL);
	if (button7 == NULL) {
		printk("Error: didn't find %s device\n", SW6_GPIO_LABEL);
		return;
	}

	//Binding button to SW7
	button8 = device_get_binding(SW7_GPIO_LABEL);
	if (button8 == NULL) {
		printk("Error: didn't find %s device\n", SW7_GPIO_LABEL);
		return;
	}

	//Binding button to SW7
	button9 = device_get_binding(SW8_GPIO_LABEL);
	if (button9 == NULL) {
		printk("Error: didn't find %s device\n", SW8_GPIO_LABEL);
		return;
	}

	//gpio pin configure
	ret = gpio_pin_configure(button, SW0_GPIO_PIN, SW0_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW0_GPIO_LABEL, SW0_GPIO_PIN);
		return;
	}

	ret = gpio_pin_configure(button, SW1_GPIO_PIN, SW1_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW1_GPIO_LABEL, SW1_GPIO_PIN);
		return;
	}

	ret = gpio_pin_configure(button, SW2_GPIO_PIN, SW2_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW2_GPIO_LABEL, SW2_GPIO_PIN);
		return;
	}

	ret = gpio_pin_configure(button, SW3_GPIO_PIN, SW3_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW3_GPIO_LABEL, SW3_GPIO_PIN);
		return;
	}

	ret = gpio_pin_configure(button, SW4_GPIO_PIN, SW4_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW4_GPIO_LABEL, SW4_GPIO_PIN);
		return;
	}

	ret = gpio_pin_configure(button, SW5_GPIO_PIN, SW5_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW5_GPIO_LABEL, SW5_GPIO_PIN);
		return;
	}

	ret = gpio_pin_configure(button, SW6_GPIO_PIN, SW6_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW6_GPIO_LABEL, SW6_GPIO_PIN);
		return;
	}

	ret = gpio_pin_configure(button, SW7_GPIO_PIN, SW7_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW7_GPIO_LABEL, SW7_GPIO_PIN);
		return;
	}

	ret = gpio_pin_configure(button, SW8_GPIO_PIN, SW8_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, SW8_GPIO_LABEL, SW8_GPIO_PIN);
		return;
	}
	//interrupt configure
	ret = gpio_pin_interrupt_configure(button,
					   SW0_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW0_GPIO_LABEL, SW0_GPIO_PIN);
		return;
	}

	ret = gpio_pin_interrupt_configure(button,
					   SW1_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW1_GPIO_LABEL, SW1_GPIO_PIN);
		return;
	}

	ret = gpio_pin_interrupt_configure(button,
					   SW2_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW2_GPIO_LABEL, SW2_GPIO_PIN);
		return;
	}

	ret = gpio_pin_interrupt_configure(button,
					   SW3_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW3_GPIO_LABEL, SW3_GPIO_PIN);
		return;
	}

	ret = gpio_pin_interrupt_configure(button,
					   SW4_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW4_GPIO_LABEL, SW4_GPIO_PIN);
		return;
	}

	ret = gpio_pin_interrupt_configure(button,
					   SW5_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW5_GPIO_LABEL, SW5_GPIO_PIN);
		return;
	}

	ret = gpio_pin_interrupt_configure(button,
					   SW6_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW6_GPIO_LABEL, SW6_GPIO_PIN);
		return;
	}

	ret = gpio_pin_interrupt_configure(button,
					   SW7_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW7_GPIO_LABEL, SW7_GPIO_PIN);
		return;
	}

	ret = gpio_pin_interrupt_configure(button,
					   SW8_GPIO_PIN,
					   GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, SW8_GPIO_LABEL, SW8_GPIO_PIN);
		return;
	}
	//Set up button
	gpio_init_callback(&button_cb_data, button_pressed, BIT(SW0_GPIO_PIN));
	gpio_add_callback(button, &button_cb_data);
	printk("Set up button at %s pin %d (PRESS - SMOKE ALARM ACTIVE, RELEASE - SMOKE ALARM DESACTTIVE)\n", SW0_GPIO_LABEL, SW0_GPIO_PIN);

	gpio_init_callback(&button2_cb_data, button_pressed2, BIT(SW1_GPIO_PIN));
	gpio_add_callback(button2, &button2_cb_data);
	printk("Set up button at %s pin %d (PRESS - BURGLAR ALARM ACTIVE, RELEASE - BULGLAR ALARM DESACTTIVE)\n", SW1_GPIO_LABEL, SW1_GPIO_PIN);

	gpio_init_callback(&button3_cb_data, button_pressed3, BIT(SW2_GPIO_PIN));
	gpio_add_callback(button3, &button3_cb_data);
	printk("Set up button at %s pin %d (PRESS - BATHROOM LIGHT ACTIVE, RELEASE - BATHROOM LIGHT DESACTTIVE)\n", SW2_GPIO_LABEL, SW2_GPIO_PIN);

	gpio_init_callback(&button4_cb_data, button_pressed4, BIT(SW3_GPIO_PIN));
	gpio_add_callback(button4, &button4_cb_data);
	printk("Set up button at %s pin %d (If you change from release to press, the number of letters will increment.)\n", SW3_GPIO_LABEL, SW3_GPIO_PIN);

	gpio_init_callback(&button5_cb_data, button_pressed5, BIT(SW4_GPIO_PIN));
	gpio_add_callback(button5, &button5_cb_data);
	printk("Set up button at %s pin %d (If you change from release to press, the mailbox will be empty.)\n", SW4_GPIO_LABEL, SW4_GPIO_PIN);

	gpio_init_callback(&button6_cb_data, button_pressed6, BIT(SW5_GPIO_PIN));
	gpio_add_callback(button6, &button6_cb_data);
	printk("Set up button at %s pin %d (Press to open blind)\n", SW5_GPIO_LABEL, SW5_GPIO_PIN);

	gpio_init_callback(&button7_cb_data, button_pressed7, BIT(SW6_GPIO_PIN));
	gpio_add_callback(button7, &button7_cb_data);
	printk("Set up button at %s pin %d (Press to close blind)\n", SW6_GPIO_LABEL, SW6_GPIO_PIN);

	gpio_init_callback(&button8_cb_data, button_pressed8, BIT(SW7_GPIO_PIN));
	gpio_add_callback(button8, &button8_cb_data);
	printk("Set up button at %s pin %d (Press if blind is opened)\n", SW7_GPIO_LABEL, SW7_GPIO_PIN);

	gpio_init_callback(&button9_cb_data, button_pressed9, BIT(SW8_GPIO_PIN));
	gpio_add_callback(button9, &button9_cb_data);
	printk("Set up button at %s pin %d (Press if blind is closed)\n", SW8_GPIO_LABEL, SW8_GPIO_PIN);

	


	//Led initialize
	led = initialize_led();

	led2 = initialize_led2();

	led3 = initialize_led3();

	led4 = initialize_led4();

	led5 = initialize_led5();

	printk("Press the button\n");
	while (1) {
		match_led_to_button(button, led);
		match_led_to_button2(button2, led2);
		match_led_to_button3(button3, led3);
		match_led_to_button678(button6, button7, button8, led4);
		match_led_to_button679(button6, button7, button9, led5);
		k_msleep(SLEEP_TIME_MS);
	}
}

/*
 * The led0 devicetree alias is optional. If present, we'll use it
 * to turn on the LED whenever the button is pressed.
 */

#define LED0_NODE	DT_ALIAS(led0)

#if DT_NODE_HAS_STATUS(LED0_NODE, okay) && DT_NODE_HAS_PROP(LED0_NODE, gpios)
#define LED0_GPIO_LABEL	DT_GPIO_LABEL(LED0_NODE, gpios)
#define LED0_GPIO_PIN	DT_GPIO_PIN(LED0_NODE, gpios)
#define LED0_GPIO_FLAGS	(GPIO_OUTPUT | DT_GPIO_FLAGS(LED0_NODE, gpios))
#endif

#ifdef LED0_GPIO_LABEL
static const struct device *initialize_led(void)
{
	const struct device *led;
	int ret;

	led = device_get_binding(LED0_GPIO_LABEL);
	if (led == NULL) {
		printk("Didn't find SMOKE ALARM device %s\n", LED0_GPIO_LABEL);
		return NULL;
	}

	ret = gpio_pin_configure(led, LED0_GPIO_PIN, LED0_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure SMOKE ALARM device %s pin %d\n",
		       ret, LED0_GPIO_LABEL, LED0_GPIO_PIN);
		return NULL;
	}

	printk("Set up SMOKE ALARM at %s pin %d\n", LED0_GPIO_LABEL, LED0_GPIO_PIN);

	return led;
}

static void match_led_to_button(const struct device *button,
				const struct device *led)
{
	bool val;
	
	val = gpio_pin_get(button, SW0_GPIO_PIN);
	gpio_pin_set(led, LED0_GPIO_PIN, !val);

	if(val == 0)
	{	
		
		if(a==0){
			printk("SMOKE ALARM ACTIVE\n");
			a=a+1;
		}
	}
	if(val == 1)
	{	
		
		if(a==1){
			printk("SMOKE ALARM DESACTIVE\n");
			a=a-1;
		}
	}
}

#else  /* !defined(LED0_GPIO_LABEL) */
static const struct device *initialize_led(void)
{
	printk("No LED device was defined\n");
	return NULL;
}

static void match_led_to_button(const struct device *button,
				const struct device *led)
{
	return;
}
#endif	/* LED0_GPIO_LABEL */

/*
 * The led1 devicetree alias is optional. If present, we'll use it
 * to turn on the LED whenever the button is pressed.
 */

#define LED1_NODE	DT_ALIAS(led1)

#if DT_NODE_HAS_STATUS(LED1_NODE, okay) && DT_NODE_HAS_PROP(LED1_NODE, gpios)
#define LED1_GPIO_LABEL	DT_GPIO_LABEL(LED1_NODE, gpios)
#define LED1_GPIO_PIN	DT_GPIO_PIN(LED1_NODE, gpios)
#define LED1_GPIO_FLAGS	(GPIO_OUTPUT | DT_GPIO_FLAGS(LED1_NODE, gpios))
#endif

#ifdef LED1_GPIO_LABEL
static const struct device *initialize_led2(void)
{
	const struct device *led;
	int ret;

	led = device_get_binding(LED1_GPIO_LABEL);
	if (led == NULL) {
		printk("Didn't find LED device %s\n", LED1_GPIO_LABEL);
		return NULL;
	}

	ret = gpio_pin_configure(led, LED1_GPIO_PIN, LED1_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure LED device %s pin %d\n",
		       ret, LED1_GPIO_LABEL, LED1_GPIO_PIN);
		return NULL;
	}

	printk("Set up Burglar Alarm at %s pin %d\n", LED1_GPIO_LABEL, LED1_GPIO_PIN);

	return led;
}

static void match_led_to_button2(const struct device *button,
				const struct device *led)
{
	bool val;

	val = gpio_pin_get(button, SW1_GPIO_PIN);
	gpio_pin_set(led, LED1_GPIO_PIN, !val);
	if(val == 0)
	{	
		
		if(a2==0){
			printk("BURGLAR ALARM ACTIVE\n");
			a2=a2+1;
		}
	}
	if(val == 1)
	{	
		
		if(a2==1){
			printk("BURGLAR ALARM DESACTIVE\n");
			a2=a2-1;
		}
	}
}

#else  /* !defined(LED1_GPIO_LABEL) */
static const struct device *initialize_led2(void)
{
	printk("No LED device was defined\n");
	return NULL;
}

static void match_led_to_button2(const struct device *button,
				const struct device *led)
{
	return;
}
#endif	/* LED1_GPIO_LABEL */

/*
 * The led2 devicetree alias is optional. If present, we'll use it
 * to turn on the LED whenever the button is pressed.
 */

#define LED2_NODE	DT_ALIAS(led2)

#if DT_NODE_HAS_STATUS(LED2_NODE, okay) && DT_NODE_HAS_PROP(LED2_NODE, gpios)
#define LED2_GPIO_LABEL	DT_GPIO_LABEL(LED2_NODE, gpios)
#define LED2_GPIO_PIN	DT_GPIO_PIN(LED2_NODE, gpios)
#define LED2_GPIO_FLAGS	(GPIO_OUTPUT | DT_GPIO_FLAGS(LED2_NODE, gpios))
#endif

#ifdef LED2_GPIO_LABEL
static const struct device *initialize_led3(void)
{
	const struct device *led;
	int ret;

	led = device_get_binding(LED2_GPIO_LABEL);
	if (led == NULL) {
		printk("Didn't find LED device %s\n", LED2_GPIO_LABEL);
		return NULL;
	}

	ret = gpio_pin_configure(led, LED2_GPIO_PIN, LED2_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure LED device %s pin %d\n",
		       ret, LED2_GPIO_LABEL, LED2_GPIO_PIN);
		return NULL;
	}

	printk("Set up bathroom light controler at %s pin %d\n", LED2_GPIO_LABEL, LED2_GPIO_PIN);

	return led;
}

static void match_led_to_button3(const struct device *button,
				const struct device *led)
{
	bool val;

	val = gpio_pin_get(button, SW2_GPIO_PIN);
	gpio_pin_set(led, LED2_GPIO_PIN, val);
	if(val == 0)
	{	
		
		if(a3==0){
			printk("BATHROOM LIGHT ACTIVE\n");
			a3=a3+1;
		}
	}
	if(val == 1)
	{	
		
		if(a3==1){
			printk("BATHROOM LIGHT DESACTIVE\n");
			a3=a3-1;
		}
	}
}

#else  /* !defined(LED2_GPIO_LABEL) */
static const struct device *initialize_led3(void)
{
	printk("No LED device was defined\n");
	return NULL;
}

static void match_led_to_button3(const struct device *button,
				const struct device *led)
{
	return;
}
#endif	/* LED2_GPIO_LABEL */

/*
 * The led3 devicetree alias is optional. If present, we'll use it
 * to turn on the LED whenever the button is pressed.
 */

#define LED3_NODE	DT_ALIAS(led3)

#if DT_NODE_HAS_STATUS(LED3_NODE, okay) && DT_NODE_HAS_PROP(LED3_NODE, gpios)
#define LED3_GPIO_LABEL	DT_GPIO_LABEL(LED3_NODE, gpios)
#define LED3_GPIO_PIN	DT_GPIO_PIN(LED3_NODE, gpios)
#define LED3_GPIO_FLAGS	(GPIO_OUTPUT | DT_GPIO_FLAGS(LED3_NODE, gpios))
#endif

#ifdef LED3_GPIO_LABEL
static const struct device *initialize_led4(void)
{
	const struct device *led;
	int ret;

	led = device_get_binding(LED3_GPIO_LABEL);
	if (led == NULL) {
		printk("Didn't find LED device %s\n", LED3_GPIO_LABEL);
		return NULL;
	}

	ret = gpio_pin_configure(led, LED3_GPIO_PIN, LED3_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure LED device %s pin %d\n",
		       ret, LED3_GPIO_LABEL, LED3_GPIO_PIN);
		return NULL;
	}

	printk("Set up bathroom light controler at %s pin %d\n", LED3_GPIO_LABEL, LED3_GPIO_PIN);

	return led;
}

static void match_led_to_button678(const struct device *button, const struct device *button1, const struct device *button2, 
				const struct device *led)
{
	bool val, val1, val2;

	val = gpio_pin_get(button, SW5_GPIO_PIN);
	val1 = gpio_pin_get(button1, SW6_GPIO_PIN);
	val2 = gpio_pin_get(button2, SW7_GPIO_PIN);
	if(val && !val1 && !val2)
	{
		gpio_pin_set(led, LED3_GPIO_PIN, val);
	}
	else
	{
		gpio_pin_set(led, LED3_GPIO_PIN, 0);
	}
}

#else  /* !defined(LED3_GPIO_LABEL) */
static const struct device *initialize_led4(void)
{
	printk("No LED device was defined\n");
	return NULL;
}

static void match_led_to_button678(const struct device *button,
				const struct device *led)
{
	return;
}
#endif	/* LED2_GPIO_LABEL */

/*
 * The led4 devicetree alias is optional. If present, we'll use it
 * to turn on the LED whenever the button is pressed.
 */

#define LED4_NODE	DT_ALIAS(led4)

#if DT_NODE_HAS_STATUS(LED4_NODE, okay) && DT_NODE_HAS_PROP(LED4_NODE, gpios)
#define LED4_GPIO_LABEL	DT_GPIO_LABEL(LED4_NODE, gpios)
#define LED4_GPIO_PIN	DT_GPIO_PIN(LED4_NODE, gpios)
#define LED4_GPIO_FLAGS	(GPIO_OUTPUT | DT_GPIO_FLAGS(LED4_NODE, gpios))
#endif

#ifdef LED4_GPIO_LABEL
static const struct device *initialize_led5(void)
{
	const struct device *led;
	int ret;

	led = device_get_binding(LED4_GPIO_LABEL);
	if (led == NULL) {
		printk("Didn't find LED device %s\n", LED4_GPIO_LABEL);
		return NULL;
	}

	ret = gpio_pin_configure(led, LED4_GPIO_PIN, LED4_GPIO_FLAGS);
	if (ret != 0) {
		printk("Error %d: failed to configure LED device %s pin %d\n",
		       ret, LED4_GPIO_LABEL, LED4_GPIO_PIN);
		return NULL;
	}

	printk("Set up bathroom light controler at %s pin %d\n", LED4_GPIO_LABEL, LED4_GPIO_PIN);

	return led;
}

static void match_led_to_button679(const struct device *button, const struct device *button1, const struct device *button2, 
				const struct device *led)
{
	bool val, val1, val2;

	val = gpio_pin_get(button, SW5_GPIO_PIN);
	val1 = gpio_pin_get(button1, SW6_GPIO_PIN);
	val2 = gpio_pin_get(button2, SW8_GPIO_PIN);
	if(!val && val1 && !val2)
	{
		gpio_pin_set(led, LED4_GPIO_PIN, 1);
	}
	else
	{
		gpio_pin_set(led, LED4_GPIO_PIN, 0);
	}
	
}

#else  /* !defined(LED4_GPIO_LABEL) */
static const struct device *initialize_led5(void)
{
	printk("No LED device was defined\n");
	return NULL;
}

static void match_led_to_button679(const struct device *button,
				const struct device *led)
{
	return;
}
#endif	/* LED2_GPIO_LABEL */
