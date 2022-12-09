
typedef __INT8_TYPE__ sint8;
typedef __INT16_TYPE__ sint16;
typedef __INT32_TYPE__ sint32;
typedef __INT64_TYPE__ sint64;
typedef __UINT8_TYPE__ uint8;
typedef __UINT16_TYPE__ uint16;
typedef __UINT32_TYPE__ uint32;
typedef __UINT64_TYPE__ uint64;
typedef uint8 bool;
enum { true = 1, false = 0 };

#define _TOKEN_PASTE(x, y) x##y
#define TOKEN_PASTE(x, y) _TOKEN_PASTE(x, y)

#define compiler_assert_nr(e, nr)                                          \
	static void TOKEN_PASTE(TOKEN_PASTE(compiler_assert, __COUNTER__), \
				__LINE__)(void)                            \
	{                                                                  \
		switch ((nr)) {                                            \
		case (nr):                                                 \
			break;                                             \
		case (e) ? (nr)-1:                                         \
			(nr)                                               \
				: break;                                   \
		}                                                          \
	}

#define compiler_assert_nr_func(e, nr)   \
	{                                \
		switch ((nr)) {          \
		case (nr):               \
			break;           \
		case (e) ? (nr)-1:       \
			(nr)             \
				: break; \
		}                        \
	}

#define compiler_print_nr(nr, f) compiler_assert_nr(0, nr, f)


// 8ed710da2873c2aeb3bb805864a699affaf1d03b

/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * This file holds USB constants and structures that are needed for
 * USB device APIs.  These are used by the USB device model, which is
 * defined in chapter 9 of the USB 2.0 specification and in the
 * Wireless USB 1.0 (spread around).  Linux has several APIs in C that
 * need these:
 *
 * - the master/host side Linux-USB kernel driver API;
 * - the "usbfs" user space API; and
 * - the Linux "gadget" slave/device/peripheral side driver API.
 *
 * USB 2.0 adds an additional "On The Go" (OTG) mode, which lets systems
 * act either as a USB master/host or as a USB slave/device.  That means
 * the master and slave side APIs benefit from working well together.
 *
 * There's also "Wireless USB", using low power short range radios for
 * peripheral interconnection but otherwise building on the USB framework.
 *
 * Note all descriptors are declared '__attribute__((packed))' so that:
 *
 * [a] they never get padded, either internally (USB spec writers
 *     probably handled that) or externally;
 *
 * [b] so that accessing bigger-than-a-bytes fields will never
 *     generate bus errors on any platform, even when the location of
 *     its descriptor inside a bundle isn't "naturally aligned", and
 *
 * [c] for consistency, removing all doubt even when it appears to
 *     someone that the two other points are non-issues for that
 *     particular descriptor type.
//  */

// #ifndef _UAPI__LINUX_USB_CH9_H
// #define _UAPI__LINUX_USB_CH9_H

// #include <linux/types.h>	/* __u8 etc */
// #include <asm/byteorder.h>	/* le16_to_cpu */

// /*-------------------------------------------------------------------------*/

// /* CONTROL REQUEST SUPPORT */

// /*
//  * USB directions
//  *
//  * This bit flag is used in endpoint descriptors' bEndpointAddress field.
//  * It's also one of three fields in control requests bRequestType.
//  */
// #define USB_DIR_OUT			0		/* to device */
// #define USB_DIR_IN			0x80		/* to host */

// /*
//  * USB types, the second of three bRequestType fields
//  */
// #define USB_TYPE_MASK			(0x03 << 5)
// #define USB_TYPE_STANDARD		(0x00 << 5)
// #define USB_TYPE_CLASS			(0x01 << 5)
// #define USB_TYPE_VENDOR			(0x02 << 5)
// #define USB_TYPE_RESERVED		(0x03 << 5)

// /*
//  * USB recipients, the third of three bRequestType fields
//  */
// #define USB_RECIP_MASK			0x1f
// #define USB_RECIP_DEVICE		0x00
// #define USB_RECIP_INTERFACE		0x01
// #define USB_RECIP_ENDPOINT		0x02
// #define USB_RECIP_OTHER			0x03
// /* From Wireless USB 1.0 */
// #define USB_RECIP_PORT			0x04
// #define USB_RECIP_RPIPE		0x05

// /*
//  * Standard requests, for the bRequest field of a SETUP packet.
//  *
//  * These are qualified by the bRequestType field, so that for example
//  * TYPE_CLASS or TYPE_VENDOR specific feature flags could be retrieved
//  * by a GET_STATUS request.
//  */
// #define USB_REQ_GET_STATUS		0x00
// #define USB_REQ_CLEAR_FEATURE		0x01
// #define USB_REQ_SET_FEATURE		0x03
// #define USB_REQ_SET_ADDRESS		0x05
// #define USB_REQ_GET_DESCRIPTOR		0x06
// #define USB_REQ_SET_DESCRIPTOR		0x07
// #define USB_REQ_GET_CONFIGURATION	0x08
// #define USB_REQ_SET_CONFIGURATION	0x09
// #define USB_REQ_GET_INTERFACE		0x0A
// #define USB_REQ_SET_INTERFACE		0x0B
// #define USB_REQ_SYNCH_FRAME		0x0C
// #define USB_REQ_SET_SEL			0x30
// #define USB_REQ_SET_ISOCH_DELAY		0x31

// #define USB_REQ_SET_ENCRYPTION		0x0D	/* Wireless USB */
// #define USB_REQ_GET_ENCRYPTION		0x0E
// #define USB_REQ_RPIPE_ABORT		0x0E
// #define USB_REQ_SET_HANDSHAKE		0x0F
// #define USB_REQ_RPIPE_RESET		0x0F
// #define USB_REQ_GET_HANDSHAKE		0x10
// #define USB_REQ_SET_CONNECTION		0x11
// #define USB_REQ_SET_SECURITY_DATA	0x12
// #define USB_REQ_GET_SECURITY_DATA	0x13
// #define USB_REQ_SET_WUSB_DATA		0x14
// #define USB_REQ_LOOPBACK_DATA_WRITE	0x15
// #define USB_REQ_LOOPBACK_DATA_READ	0x16
// #define USB_REQ_SET_INTERFACE_DS	0x17

// /* specific requests for USB Power Delivery */
// #define USB_REQ_GET_PARTNER_PDO		20
// #define USB_REQ_GET_BATTERY_STATUS	21
// #define USB_REQ_SET_PDO			22
// #define USB_REQ_GET_VDM			23
// #define USB_REQ_SEND_VDM		24

// /* The Link Power Management (LPM) ECN defines USB_REQ_TEST_AND_SET command,
//  * used by hubs to put ports into a new L1 suspend state, except that it
//  * forgot to define its number ...
//  */

// /*
//  * USB feature flags are written using USB_REQ_{CLEAR,SET}_FEATURE, and
//  * are read as a bit array returned by USB_REQ_GET_STATUS.  (So there
//  * are at most sixteen features of each type.)  Hubs may also support a
//  * new USB_REQ_TEST_AND_SET_FEATURE to put ports into L1 suspend.
//  */
// #define USB_DEVICE_SELF_POWERED		0	/* (read only) */
// #define USB_DEVICE_REMOTE_WAKEUP	1	/* dev may initiate wakeup */
// #define USB_DEVICE_TEST_MODE		2	/* (wired high speed only) */
// #define USB_DEVICE_BATTERY		2	/* (wireless) */
// #define USB_DEVICE_B_HNP_ENABLE		3	/* (otg) dev may initiate HNP */
// #define USB_DEVICE_WUSB_DEVICE		3	/* (wireless)*/
// #define USB_DEVICE_A_HNP_SUPPORT	4	/* (otg) RH port supports HNP */
// #define USB_DEVICE_A_ALT_HNP_SUPPORT	5	/* (otg) other RH port does */
// #define USB_DEVICE_DEBUG_MODE		6	/* (special devices only) */

// /*
//  * Test Mode Selectors
//  * See USB 2.0 spec Table 9-7
//  */
// #define	USB_TEST_J		1
// #define	USB_TEST_K		2
// #define	USB_TEST_SE0_NAK	3
// #define	USB_TEST_PACKET		4
// #define	USB_TEST_FORCE_ENABLE	5

// /* Status Type */
// #define USB_STATUS_TYPE_STANDARD	0
// #define USB_STATUS_TYPE_PTM		1

// /*
//  * New Feature Selectors as added by USB 3.0
//  * See USB 3.0 spec Table 9-7
//  */
// #define USB_DEVICE_U1_ENABLE	48	/* dev may initiate U1 transition */
// #define USB_DEVICE_U2_ENABLE	49	/* dev may initiate U2 transition */
// #define USB_DEVICE_LTM_ENABLE	50	/* dev may send LTM */
// #define USB_INTRF_FUNC_SUSPEND	0	/* function suspend */

// #define USB_INTR_FUNC_SUSPEND_OPT_MASK	0xFF00
// /*
//  * Suspend Options, Table 9-8 USB 3.0 spec
//  */
// #define USB_INTRF_FUNC_SUSPEND_LP	(1 << (8 + 0))
// #define USB_INTRF_FUNC_SUSPEND_RW	(1 << (8 + 1))

// /*
//  * Interface status, Figure 9-5 USB 3.0 spec
//  */
// #define USB_INTRF_STAT_FUNC_RW_CAP     1
// #define USB_INTRF_STAT_FUNC_RW         2

// #define USB_ENDPOINT_HALT		0	/* IN/OUT will STALL */

// /* Bit array elements as returned by the USB_REQ_GET_STATUS request. */
// #define USB_DEV_STAT_U1_ENABLED		2	/* transition into U1 state */
// #define USB_DEV_STAT_U2_ENABLED		3	/* transition into U2 state */
// #define USB_DEV_STAT_LTM_ENABLED	4	/* Latency tolerance messages */

// /*
//  * Feature selectors from Table 9-8 USB Power Delivery spec
//  */
// #define USB_DEVICE_BATTERY_WAKE_MASK	40
// #define USB_DEVICE_OS_IS_PD_AWARE	41
// #define USB_DEVICE_POLICY_MODE		42
// #define USB_PORT_PR_SWAP		43
// #define USB_PORT_GOTO_MIN		44
// #define USB_PORT_RETURN_POWER		45
// #define USB_PORT_ACCEPT_PD_REQUEST	46
// #define USB_PORT_REJECT_PD_REQUEST	47
// #define USB_PORT_PORT_PD_RESET		48
// #define USB_PORT_C_PORT_PD_CHANGE	49
// #define USB_PORT_CABLE_PD_RESET		50
// #define USB_DEVICE_CHARGING_POLICY	54

// /**
//  * struct usb_ctrlrequest - SETUP data for a USB device control request
//  * @bRequestType: matches the USB bmRequestType field
//  * @bRequest: matches the USB bRequest field
//  * @wValue: matches the USB wValue field (le16 byte order)
//  * @wIndex: matches the USB wIndex field (le16 byte order)
//  * @wLength: matches the USB wLength field (le16 byte order)
//  *
//  * This structure is used to send control requests to a USB device.  It matches
//  * the different fields of the USB 2.0 Spec section 9.3, table 9-2.  See the
//  * USB spec for a fuller description of the different fields, and what they are
//  * used for.
//  *
//  * Note that the driver for any interface can issue control requests.
//  * For most devices, interfaces don't coordinate with each other, so
//  * such requests may be made at any time.
//  */
// struct usb_ctrlrequest {
// 	__u8 bRequestType;
// 	__u8 bRequest;
// 	__le16 wValue;
// 	__le16 wIndex;
// 	__le16 wLength;
// } __attribute__ ((packed));

// /*-------------------------------------------------------------------------*/

// /*
//  * STANDARD DESCRIPTORS ... as returned by GET_DESCRIPTOR, or
//  * (rarely) accepted by SET_DESCRIPTOR.
//  *
//  * Note that all multi-byte values here are encoded in little endian
//  * byte order "on the wire".  Within the kernel and when exposed
//  * through the Linux-USB APIs, they are not converted to cpu byte
//  * order; it is the responsibility of the client code to do this.
//  * The single exception is when device and configuration descriptors (but
//  * not other descriptors) are read from character devices
//  * (i.e. /dev/bus/usb/BBB/DDD);
//  * in this case the fields are converted to host endianness by the kernel.
//  */

// /*
//  * Descriptor types ... USB 2.0 spec table 9.5
//  */
// #define USB_DT_DEVICE			0x01
// #define USB_DT_CONFIG			0x02
// #define USB_DT_STRING			0x03
// #define USB_DT_INTERFACE		0x04
// #define USB_DT_ENDPOINT			0x05
// #define USB_DT_DEVICE_QUALIFIER		0x06
// #define USB_DT_OTHER_SPEED_CONFIG	0x07
// #define USB_DT_INTERFACE_POWER		0x08
// /* these are from a minor usb 2.0 revision (ECN) */
// #define USB_DT_OTG			0x09
// #define USB_DT_DEBUG			0x0a
// #define USB_DT_INTERFACE_ASSOCIATION	0x0b
// /* these are from the Wireless USB spec */
// #define USB_DT_SECURITY			0x0c
// #define USB_DT_KEY			0x0d
// #define USB_DT_ENCRYPTION_TYPE		0x0e
// #define USB_DT_BOS			0x0f
// #define USB_DT_DEVICE_CAPABILITY	0x10
// #define USB_DT_WIRELESS_ENDPOINT_COMP	0x11
// #define USB_DT_WIRE_ADAPTER		0x21
// #define USB_DT_RPIPE			0x22
// #define USB_DT_CS_RADIO_CONTROL		0x23
// /* From the T10 UAS specification */
// #define USB_DT_PIPE_USAGE		0x24
// /* From the USB 3.0 spec */
// #define	USB_DT_SS_ENDPOINT_COMP		0x30
// /* From the USB 3.1 spec */
// #define	USB_DT_SSP_ISOC_ENDPOINT_COMP	0x31

// /* Conventional codes for class-specific descriptors.  The convention is
//  * defined in the USB "Common Class" Spec (3.11).  Individual class specs
//  * are authoritative for their usage, not the "common class" writeup.
//  */
// #define USB_DT_CS_DEVICE		(USB_TYPE_CLASS | USB_DT_DEVICE)
// #define USB_DT_CS_CONFIG		(USB_TYPE_CLASS | USB_DT_CONFIG)
// #define USB_DT_CS_STRING		(USB_TYPE_CLASS | USB_DT_STRING)
// #define USB_DT_CS_INTERFACE		(USB_TYPE_CLASS | USB_DT_INTERFACE)
// #define USB_DT_CS_ENDPOINT		(USB_TYPE_CLASS | USB_DT_ENDPOINT)

// /* All standard descriptors have these 2 fields at the beginning */
// struct usb_descriptor_header {
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// } __attribute__ ((packed));

// /*-------------------------------------------------------------------------*/

// /* USB_DT_DEVICE: Device descriptor */
// struct usb_device_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__le16 bcdUSB;
// 	__u8  bDeviceClass;
// 	__u8  bDeviceSubClass;
// 	__u8  bDeviceProtocol;
// 	__u8  bMaxPacketSize0;
// 	__le16 idVendor;
// 	__le16 idProduct;
// 	__le16 bcdDevice;
// 	__u8  iManufacturer;
// 	__u8  iProduct;
// 	__u8  iSerialNumber;
// 	__u8  bNumConfigurations;
// } __attribute__ ((packed));

// #define USB_DT_DEVICE_SIZE		18

// /*
//  * Device and/or Interface Class codes
//  * as found in bDeviceClass or bInterfaceClass
//  * and defined by www.usb.org documents
//  */
// #define USB_CLASS_PER_INTERFACE		0	/* for DeviceClass */
// #define USB_CLASS_AUDIO			1
// #define USB_CLASS_COMM			2
// #define USB_CLASS_HID			3
// #define USB_CLASS_PHYSICAL		5
// #define USB_CLASS_STILL_IMAGE		6
// #define USB_CLASS_PRINTER		7
// #define USB_CLASS_MASS_STORAGE		8
// #define USB_CLASS_HUB			9
// #define USB_CLASS_CDC_DATA		0x0a
// #define USB_CLASS_CSCID			0x0b	/* chip+ smart card */
// #define USB_CLASS_CONTENT_SEC		0x0d	/* content security */
// #define USB_CLASS_VIDEO			0x0e
// #define USB_CLASS_WIRELESS_CONTROLLER	0xe0
// #define USB_CLASS_PERSONAL_HEALTHCARE	0x0f
// #define USB_CLASS_AUDIO_VIDEO		0x10
// #define USB_CLASS_BILLBOARD		0x11
// #define USB_CLASS_USB_TYPE_C_BRIDGE	0x12
// #define USB_CLASS_MISC			0xef
// #define USB_CLASS_APP_SPEC		0xfe
// #define USB_CLASS_VENDOR_SPEC		0xff

// #define USB_SUBCLASS_VENDOR_SPEC	0xff

// /*-------------------------------------------------------------------------*/

// /* USB_DT_CONFIG: Configuration descriptor information.
//  *
//  * USB_DT_OTHER_SPEED_CONFIG is the same descriptor, except that the
//  * descriptor type is different.  Highspeed-capable devices can look
//  * different depending on what speed they're currently running.  Only
//  * devices with a USB_DT_DEVICE_QUALIFIER have any OTHER_SPEED_CONFIG
//  * descriptors.
//  */
// struct usb_config_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__le16 wTotalLength;
// 	__u8  bNumInterfaces;
// 	__u8  bConfigurationValue;
// 	__u8  iConfiguration;
// 	__u8  bmAttributes;
// 	__u8  bMaxPower;
// } __attribute__ ((packed));

// #define USB_DT_CONFIG_SIZE		9

// /* from config descriptor bmAttributes */
// #define USB_CONFIG_ATT_ONE		(1 << 7)	/* must be set */
// #define USB_CONFIG_ATT_SELFPOWER	(1 << 6)	/* self powered */
// #define USB_CONFIG_ATT_WAKEUP		(1 << 5)	/* can wakeup */
// #define USB_CONFIG_ATT_BATTERY		(1 << 4)	/* battery powered */

// /*-------------------------------------------------------------------------*/

// /* USB String descriptors can contain at most 126 characters. */
// #define USB_MAX_STRING_LEN	126

// /* USB_DT_STRING: String descriptor */
// struct usb_string_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__le16 wData[1];		/* UTF-16LE encoded */
// } __attribute__ ((packed));

// /* note that "string" zero is special, it holds language codes that
//  * the device supports, not Unicode characters.
//  */

// /*-------------------------------------------------------------------------*/

// /* USB_DT_INTERFACE: Interface descriptor */
// struct usb_interface_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__u8  bInterfaceNumber;
// 	__u8  bAlternateSetting;
// 	__u8  bNumEndpoints;
// 	__u8  bInterfaceClass;
// 	__u8  bInterfaceSubClass;
// 	__u8  bInterfaceProtocol;
// 	__u8  iInterface;
// } __attribute__ ((packed));

// #define USB_DT_INTERFACE_SIZE		9

// /*-------------------------------------------------------------------------*/

// /* USB_DT_ENDPOINT: Endpoint descriptor */
struct usb_endpoint_descriptor {
	uint8 bLength;
	uint8 bDescriptorType;

	uint8 bEndpointAddress;
	uint8 bmAttributes;
	uint16 wMaxPacketSize;
	uint8 bInterval;

	/* NOTE:  these two are _only_ in audio endpoints. */
	/* use USB_DT_ENDPOINT*_SIZE in bLength, not sizeof. */
	uint8 bRefresh;
	uint8 bSynchAddress;
} __attribute__((packed));

#define USB_DT_ENDPOINT_SIZE 7
// #define USB_DT_ENDPOINT_AUDIO_SIZE	9	/* Audio extension */

// /*
//  * Endpoints
//  */
// #define USB_ENDPOINT_NUMBER_MASK	0x0f	/* in bEndpointAddress */
// #define USB_ENDPOINT_DIR_MASK		0x80

// #define USB_ENDPOINT_XFERTYPE_MASK	0x03	/* in bmAttributes */
// #define USB_ENDPOINT_XFER_CONTROL	0
// #define USB_ENDPOINT_XFER_ISOC		1
// #define USB_ENDPOINT_XFER_BULK		2
// #define USB_ENDPOINT_XFER_INT		3
// #define USB_ENDPOINT_MAX_ADJUSTABLE	0x80

// #define USB_ENDPOINT_MAXP_MASK	0x07ff
// #define USB_EP_MAXP_MULT_SHIFT	11
// #define USB_EP_MAXP_MULT_MASK	(3 << USB_EP_MAXP_MULT_SHIFT)
// #define USB_EP_MAXP_MULT(m) \
// 	(((m) & USB_EP_MAXP_MULT_MASK) >> USB_EP_MAXP_MULT_SHIFT)

// /* The USB 3.0 spec redefines bits 5:4 of bmAttributes as interrupt ep type. */
// #define USB_ENDPOINT_INTRTYPE		0x30
// #define USB_ENDPOINT_INTR_PERIODIC	(0 << 4)
// #define USB_ENDPOINT_INTR_NOTIFICATION	(1 << 4)

// #define USB_ENDPOINT_SYNCTYPE		0x0c
// #define USB_ENDPOINT_SYNC_NONE		(0 << 2)
// #define USB_ENDPOINT_SYNC_ASYNC		(1 << 2)
// #define USB_ENDPOINT_SYNC_ADAPTIVE	(2 << 2)
// #define USB_ENDPOINT_SYNC_SYNC		(3 << 2)

// #define USB_ENDPOINT_USAGE_MASK		0x30
// #define USB_ENDPOINT_USAGE_DATA		0x00
// #define USB_ENDPOINT_USAGE_FEEDBACK	0x10
// #define USB_ENDPOINT_USAGE_IMPLICIT_FB	0x20	/* Implicit feedback Data endpoint */

// /*-------------------------------------------------------------------------*/

// /**
//  * usb_endpoint_num - get the endpoint's number
//  * @epd: endpoint to be checked
//  *
//  * Returns @epd's number: 0 to 15.
//  */
// static inline int usb_endpoint_num(const struct usb_endpoint_descriptor *epd)
// {
// 	return epd->bEndpointAddress & USB_ENDPOINT_NUMBER_MASK;
// }

// /**
//  * usb_endpoint_type - get the endpoint's transfer type
//  * @epd: endpoint to be checked
//  *
//  * Returns one of USB_ENDPOINT_XFER_{CONTROL, ISOC, BULK, INT} according
//  * to @epd's transfer type.
//  */
// static inline int usb_endpoint_type(const struct usb_endpoint_descriptor *epd)
// {
// 	return epd->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
// }

// /**
//  * usb_endpoint_dir_in - check if the endpoint has IN direction
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint is of type IN, otherwise it returns false.
//  */
// static inline int usb_endpoint_dir_in(const struct usb_endpoint_descriptor *epd)
// {
// 	return ((epd->bEndpointAddress & USB_ENDPOINT_DIR_MASK) == USB_DIR_IN);
// }

// /**
//  * usb_endpoint_dir_out - check if the endpoint has OUT direction
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint is of type OUT, otherwise it returns false.
//  */
// static inline int usb_endpoint_dir_out(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return ((epd->bEndpointAddress & USB_ENDPOINT_DIR_MASK) == USB_DIR_OUT);
// }

// /**
//  * usb_endpoint_xfer_bulk - check if the endpoint has bulk transfer type
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint is of type bulk, otherwise it returns false.
//  */
// static inline int usb_endpoint_xfer_bulk(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return ((epd->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) ==
// 		USB_ENDPOINT_XFER_BULK);
// }

// /**
//  * usb_endpoint_xfer_control - check if the endpoint has control transfer type
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint is of type control, otherwise it returns false.
//  */
// static inline int usb_endpoint_xfer_control(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return ((epd->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) ==
// 		USB_ENDPOINT_XFER_CONTROL);
// }

// /**
//  * usb_endpoint_xfer_int - check if the endpoint has interrupt transfer type
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint is of type interrupt, otherwise it returns
//  * false.
//  */
// static inline int usb_endpoint_xfer_int(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return ((epd->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) ==
// 		USB_ENDPOINT_XFER_INT);
// }

// /**
//  * usb_endpoint_xfer_isoc - check if the endpoint has isochronous transfer type
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint is of type isochronous, otherwise it returns
//  * false.
//  */
// static inline int usb_endpoint_xfer_isoc(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return ((epd->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) ==
// 		USB_ENDPOINT_XFER_ISOC);
// }

// /**
//  * usb_endpoint_is_bulk_in - check if the endpoint is bulk IN
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint has bulk transfer type and IN direction,
//  * otherwise it returns false.
//  */
// static inline int usb_endpoint_is_bulk_in(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return usb_endpoint_xfer_bulk(epd) && usb_endpoint_dir_in(epd);
// }

// /**
//  * usb_endpoint_is_bulk_out - check if the endpoint is bulk OUT
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint has bulk transfer type and OUT direction,
//  * otherwise it returns false.
//  */
// static inline int usb_endpoint_is_bulk_out(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return usb_endpoint_xfer_bulk(epd) && usb_endpoint_dir_out(epd);
// }

// /**
//  * usb_endpoint_is_int_in - check if the endpoint is interrupt IN
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint has interrupt transfer type and IN direction,
//  * otherwise it returns false.
//  */
// static inline int usb_endpoint_is_int_in(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return usb_endpoint_xfer_int(epd) && usb_endpoint_dir_in(epd);
// }

// /**
//  * usb_endpoint_is_int_out - check if the endpoint is interrupt OUT
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint has interrupt transfer type and OUT direction,
//  * otherwise it returns false.
//  */
// static inline int usb_endpoint_is_int_out(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return usb_endpoint_xfer_int(epd) && usb_endpoint_dir_out(epd);
// }

// /**
//  * usb_endpoint_is_isoc_in - check if the endpoint is isochronous IN
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint has isochronous transfer type and IN direction,
//  * otherwise it returns false.
//  */
// static inline int usb_endpoint_is_isoc_in(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return usb_endpoint_xfer_isoc(epd) && usb_endpoint_dir_in(epd);
// }

// /**
//  * usb_endpoint_is_isoc_out - check if the endpoint is isochronous OUT
//  * @epd: endpoint to be checked
//  *
//  * Returns true if the endpoint has isochronous transfer type and OUT direction,
//  * otherwise it returns false.
//  */
// static inline int usb_endpoint_is_isoc_out(
// 				const struct usb_endpoint_descriptor *epd)
// {
// 	return usb_endpoint_xfer_isoc(epd) && usb_endpoint_dir_out(epd);
// }

// /**
//  * usb_endpoint_maxp - get endpoint's max packet size
//  * @epd: endpoint to be checked
//  *
//  * Returns @epd's max packet bits [10:0]
//  */
// static inline int usb_endpoint_maxp(const struct usb_endpoint_descriptor *epd)
// {
// 	return __le16_to_cpu(epd->wMaxPacketSize) & USB_ENDPOINT_MAXP_MASK;
// }

// /**
//  * usb_endpoint_maxp_mult - get endpoint's transactional opportunities
//  * @epd: endpoint to be checked
//  *
//  * Return @epd's wMaxPacketSize[12:11] + 1
//  */
// static inline int
// usb_endpoint_maxp_mult(const struct usb_endpoint_descriptor *epd)
// {
// 	int maxp = __le16_to_cpu(epd->wMaxPacketSize);

// 	return USB_EP_MAXP_MULT(maxp) + 1;
// }

// static inline int usb_endpoint_interrupt_type(
// 		const struct usb_endpoint_descriptor *epd)
// {
// 	return epd->bmAttributes & USB_ENDPOINT_INTRTYPE;
// }

// /*-------------------------------------------------------------------------*/

// /* USB_DT_SSP_ISOC_ENDPOINT_COMP: SuperSpeedPlus Isochronous Endpoint Companion
//  * descriptor
//  */
// struct usb_ssp_isoc_ep_comp_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__le16 wReseved;
// 	__le32 dwBytesPerInterval;
// } __attribute__ ((packed));

// #define USB_DT_SSP_ISOC_EP_COMP_SIZE		8

// /*-------------------------------------------------------------------------*/

// /* USB_DT_SS_ENDPOINT_COMP: SuperSpeed Endpoint Companion descriptor */
// struct usb_ss_ep_comp_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__u8  bMaxBurst;
// 	__u8  bmAttributes;
// 	__le16 wBytesPerInterval;
// } __attribute__ ((packed));

// #define USB_DT_SS_EP_COMP_SIZE		6

// /* Bits 4:0 of bmAttributes if this is a bulk endpoint */
// static inline int
// usb_ss_max_streams(const struct usb_ss_ep_comp_descriptor *comp)
// {
// 	int		max_streams;

// 	if (!comp)
// 		return 0;

// 	max_streams = comp->bmAttributes & 0x1f;

// 	if (!max_streams)
// 		return 0;

// 	max_streams = 1 << max_streams;

// 	return max_streams;
// }

// /* Bits 1:0 of bmAttributes if this is an isoc endpoint */
// #define USB_SS_MULT(p)			(1 + ((p) & 0x3))
// /* Bit 7 of bmAttributes if a SSP isoc endpoint companion descriptor exists */
// #define USB_SS_SSP_ISOC_COMP(p)		((p) & (1 << 7))

// /*-------------------------------------------------------------------------*/

// /* USB_DT_DEVICE_QUALIFIER: Device Qualifier descriptor */
// struct usb_qualifier_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__le16 bcdUSB;
// 	__u8  bDeviceClass;
// 	__u8  bDeviceSubClass;
// 	__u8  bDeviceProtocol;
// 	__u8  bMaxPacketSize0;
// 	__u8  bNumConfigurations;
// 	__u8  bRESERVED;
// } __attribute__ ((packed));

// /*-------------------------------------------------------------------------*/

// /* USB_DT_OTG (from OTG 1.0a supplement) */
// struct usb_otg_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__u8  bmAttributes;	/* support for HNP, SRP, etc */
// } __attribute__ ((packed));

// /* USB_DT_OTG (from OTG 2.0 supplement) */
// struct usb_otg20_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__u8  bmAttributes;	/* support for HNP, SRP and ADP, etc */
// 	__le16 bcdOTG;		/* OTG and EH supplement release number
// 				 * in binary-coded decimal(i.e. 2.0 is 0200H)
// 				 */
// } __attribute__ ((packed));

// /* from usb_otg_descriptor.bmAttributes */
// #define USB_OTG_SRP		(1 << 0)
// #define USB_OTG_HNP		(1 << 1)	/* swap host/device roles */
// #define USB_OTG_ADP		(1 << 2)	/* support ADP */

// #define OTG_STS_SELECTOR	0xF000		/* OTG status selector */
// /*-------------------------------------------------------------------------*/

// /* USB_DT_DEBUG:  for special highspeed devices, replacing serial console */
// struct usb_debug_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	/* bulk endpoints with 8 byte maxpacket */
// 	__u8  bDebugInEndpoint;
// 	__u8  bDebugOutEndpoint;
// } __attribute__((packed));

// /*-------------------------------------------------------------------------*/

// /* USB_DT_INTERFACE_ASSOCIATION: groups interfaces */
// struct usb_interface_assoc_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__u8  bFirstInterface;
// 	__u8  bInterfaceCount;
// 	__u8  bFunctionClass;
// 	__u8  bFunctionSubClass;
// 	__u8  bFunctionProtocol;
// 	__u8  iFunction;
// } __attribute__ ((packed));

// #define USB_DT_INTERFACE_ASSOCIATION_SIZE	8

// /*-------------------------------------------------------------------------*/

// /* USB_DT_SECURITY:  group of wireless security descriptors, including
//  * encryption types available for setting up a CC/association.
//  */
// struct usb_security_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__le16 wTotalLength;
// 	__u8  bNumEncryptionTypes;
// } __attribute__((packed));

// /*-------------------------------------------------------------------------*/

// /* USB_DT_KEY:  used with {GET,SET}_SECURITY_DATA; only public keys
//  * may be retrieved.
//  */
// struct usb_key_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__u8  tTKID[3];
// 	__u8  bReserved;
// 	__u8  bKeyData[];
// } __attribute__((packed));

// /*-------------------------------------------------------------------------*/

// /* USB_DT_ENCRYPTION_TYPE:  bundled in DT_SECURITY groups */
// struct usb_encryption_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__u8  bEncryptionType;
// #define	USB_ENC_TYPE_UNSECURE		0
// #define	USB_ENC_TYPE_WIRED		1	/* non-wireless mode */
// #define	USB_ENC_TYPE_CCM_1		2	/* aes128/cbc session */
// #define	USB_ENC_TYPE_RSA_1		3	/* rsa3072/sha1 auth */
// 	__u8  bEncryptionValue;		/* use in SET_ENCRYPTION */
// 	__u8  bAuthKeyIndex;
// } __attribute__((packed));

// /*-------------------------------------------------------------------------*/

// /* USB_DT_BOS:  group of device-level capabilities */
// struct usb_bos_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__le16 wTotalLength;
// 	__u8  bNumDeviceCaps;
// } __attribute__((packed));

// #define USB_DT_BOS_SIZE		5
// /*-------------------------------------------------------------------------*/

// /* USB_DT_DEVICE_CAPABILITY:  grouped with BOS */
// struct usb_dev_cap_header {
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__u8  bDevCapabilityType;
// } __attribute__((packed));

// #define	USB_CAP_TYPE_WIRELESS_USB	1

// struct usb_wireless_cap_descriptor {	/* Ultra Wide Band */
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__u8  bDevCapabilityType;

// 	__u8  bmAttributes;
// #define	USB_WIRELESS_P2P_DRD		(1 << 1)
// #define	USB_WIRELESS_BEACON_MASK	(3 << 2)
// #define	USB_WIRELESS_BEACON_SELF	(1 << 2)
// #define	USB_WIRELESS_BEACON_DIRECTED	(2 << 2)
// #define	USB_WIRELESS_BEACON_NONE	(3 << 2)
// 	__le16 wPHYRates;	/* bit rates, Mbps */
// #define	USB_WIRELESS_PHY_53		(1 << 0)	/* always set */
// #define	USB_WIRELESS_PHY_80		(1 << 1)
// #define	USB_WIRELESS_PHY_107		(1 << 2)	/* always set */
// #define	USB_WIRELESS_PHY_160		(1 << 3)
// #define	USB_WIRELESS_PHY_200		(1 << 4)	/* always set */
// #define	USB_WIRELESS_PHY_320		(1 << 5)
// #define	USB_WIRELESS_PHY_400		(1 << 6)
// #define	USB_WIRELESS_PHY_480		(1 << 7)
// 	__u8  bmTFITXPowerInfo;	/* TFI power levels */
// 	__u8  bmFFITXPowerInfo;	/* FFI power levels */
// 	__le16 bmBandGroup;
// 	__u8  bReserved;
// } __attribute__((packed));

// #define USB_DT_USB_WIRELESS_CAP_SIZE	11

// /* USB 2.0 Extension descriptor */
// #define	USB_CAP_TYPE_EXT		2

// struct usb_ext_cap_descriptor {		/* Link Power Management */
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__u8  bDevCapabilityType;
// 	__le32 bmAttributes;
// #define USB_LPM_SUPPORT			(1 << 1)	/* supports LPM */
// #define USB_BESL_SUPPORT		(1 << 2)	/* supports BESL */
// #define USB_BESL_BASELINE_VALID		(1 << 3)	/* Baseline BESL valid*/
// #define USB_BESL_DEEP_VALID		(1 << 4)	/* Deep BESL valid */
// #define USB_SET_BESL_BASELINE(p)	(((p) & 0xf) << 8)
// #define USB_SET_BESL_DEEP(p)		(((p) & 0xf) << 12)
// #define USB_GET_BESL_BASELINE(p)	(((p) & (0xf << 8)) >> 8)
// #define USB_GET_BESL_DEEP(p)		(((p) & (0xf << 12)) >> 12)
// } __attribute__((packed));

// #define USB_DT_USB_EXT_CAP_SIZE	7

// /*
//  * SuperSpeed USB Capability descriptor: Defines the set of SuperSpeed USB
//  * specific device level capabilities
//  */
// #define		USB_SS_CAP_TYPE		3
// struct usb_ss_cap_descriptor {		/* Link Power Management */
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__u8  bDevCapabilityType;
// 	__u8  bmAttributes;
// #define USB_LTM_SUPPORT			(1 << 1) /* supports LTM */
// 	__le16 wSpeedSupported;
// #define USB_LOW_SPEED_OPERATION		(1)	 /* Low speed operation */
// #define USB_FULL_SPEED_OPERATION	(1 << 1) /* Full speed operation */
// #define USB_HIGH_SPEED_OPERATION	(1 << 2) /* High speed operation */
// #define USB_5GBPS_OPERATION		(1 << 3) /* Operation at 5Gbps */
// 	__u8  bFunctionalitySupport;
// 	__u8  bU1devExitLat;
// 	__le16 bU2DevExitLat;
// } __attribute__((packed));

// #define USB_DT_USB_SS_CAP_SIZE	10

// /*
//  * Container ID Capability descriptor: Defines the instance unique ID used to
//  * identify the instance across all operating modes
//  */
// #define	CONTAINER_ID_TYPE	4
// struct usb_ss_container_id_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__u8  bDevCapabilityType;
// 	__u8  bReserved;
// 	__u8  ContainerID[16]; /* 128-bit number */
// } __attribute__((packed));

// #define USB_DT_USB_SS_CONTN_ID_SIZE	20

// /*
//  * SuperSpeed Plus USB Capability descriptor: Defines the set of
//  * SuperSpeed Plus USB specific device level capabilities
//  */
// #define	USB_SSP_CAP_TYPE	0xa
// struct usb_ssp_cap_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__u8  bDevCapabilityType;
// 	__u8  bReserved;
// 	__le32 bmAttributes;
// #define USB_SSP_SUBLINK_SPEED_ATTRIBS	(0x1f << 0) /* sublink speed entries */
// #define USB_SSP_SUBLINK_SPEED_IDS	(0xf << 5)  /* speed ID entries */
// 	__le16  wFunctionalitySupport;
// #define USB_SSP_MIN_SUBLINK_SPEED_ATTRIBUTE_ID	(0xf)
// #define USB_SSP_MIN_RX_LANE_COUNT		(0xf << 8)
// #define USB_SSP_MIN_TX_LANE_COUNT		(0xf << 12)
// 	__le16 wReserved;
// 	__le32 bmSublinkSpeedAttr[1]; /* list of sublink speed attrib entries */
// #define USB_SSP_SUBLINK_SPEED_SSID	(0xf)		/* sublink speed ID */
// #define USB_SSP_SUBLINK_SPEED_LSE	(0x3 << 4)	/* Lanespeed exponent */
// #define USB_SSP_SUBLINK_SPEED_LSE_BPS		0
// #define USB_SSP_SUBLINK_SPEED_LSE_KBPS		1
// #define USB_SSP_SUBLINK_SPEED_LSE_MBPS		2
// #define USB_SSP_SUBLINK_SPEED_LSE_GBPS		3

// #define USB_SSP_SUBLINK_SPEED_ST	(0x3 << 6)	/* Sublink type */
// #define USB_SSP_SUBLINK_SPEED_ST_SYM_RX		0
// #define USB_SSP_SUBLINK_SPEED_ST_ASYM_RX	1
// #define USB_SSP_SUBLINK_SPEED_ST_SYM_TX		2
// #define USB_SSP_SUBLINK_SPEED_ST_ASYM_TX	3

// #define USB_SSP_SUBLINK_SPEED_RSVD	(0x3f << 8)	/* Reserved */
// #define USB_SSP_SUBLINK_SPEED_LP	(0x3 << 14)	/* Link protocol */
// #define USB_SSP_SUBLINK_SPEED_LP_SS		0
// #define USB_SSP_SUBLINK_SPEED_LP_SSP		1

// #define USB_SSP_SUBLINK_SPEED_LSM	(0xff << 16)	/* Lanespeed mantissa */
// } __attribute__((packed));

// /*
//  * USB Power Delivery Capability Descriptor:
//  * Defines capabilities for PD
//  */
// /* Defines the various PD Capabilities of this device */
// #define USB_PD_POWER_DELIVERY_CAPABILITY	0x06
// /* Provides information on each battery supported by the device */
// #define USB_PD_BATTERY_INFO_CAPABILITY		0x07
// /* The Consumer characteristics of a Port on the device */
// #define USB_PD_PD_CONSUMER_PORT_CAPABILITY	0x08
// /* The provider characteristics of a Port on the device */
// #define USB_PD_PD_PROVIDER_PORT_CAPABILITY	0x09

// struct usb_pd_cap_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__u8  bDevCapabilityType; /* set to USB_PD_POWER_DELIVERY_CAPABILITY */
// 	__u8  bReserved;
// 	__le32 bmAttributes;
// #define USB_PD_CAP_BATTERY_CHARGING	(1 << 1) /* supports Battery Charging specification */
// #define USB_PD_CAP_USB_PD		(1 << 2) /* supports USB Power Delivery specification */
// #define USB_PD_CAP_PROVIDER		(1 << 3) /* can provide power */
// #define USB_PD_CAP_CONSUMER		(1 << 4) /* can consume power */
// #define USB_PD_CAP_CHARGING_POLICY	(1 << 5) /* supports CHARGING_POLICY feature */
// #define USB_PD_CAP_TYPE_C_CURRENT	(1 << 6) /* supports power capabilities defined in the USB Type-C Specification */

// #define USB_PD_CAP_PWR_AC		(1 << 8)
// #define USB_PD_CAP_PWR_BAT		(1 << 9)
// #define USB_PD_CAP_PWR_USE_V_BUS	(1 << 14)

// 	__le16 bmProviderPorts; /* Bit zero refers to the UFP of the device */
// 	__le16 bmConsumerPorts;
// 	__le16 bcdBCVersion;
// 	__le16 bcdPDVersion;
// 	__le16 bcdUSBTypeCVersion;
// } __attribute__((packed));

// struct usb_pd_cap_battery_info_descriptor {
// 	__u8 bLength;
// 	__u8 bDescriptorType;
// 	__u8 bDevCapabilityType;
// 	/* Index of string descriptor shall contain the user friendly name for this battery */
// 	__u8 iBattery;
// 	/* Index of string descriptor shall contain the Serial Number String for this battery */
// 	__u8 iSerial;
// 	__u8 iManufacturer;
// 	__u8 bBatteryId; /* uniquely identifies this battery in status Messages */
// 	__u8 bReserved;
// 	/*
// 	 * Shall contain the Battery Charge value above which this
// 	 * battery is considered to be fully charged but not necessarily
// 	 * “topped off.”
// 	 */
// 	__le32 dwChargedThreshold; /* in mWh */
// 	/*
// 	 * Shall contain the minimum charge level of this battery such
// 	 * that above this threshold, a device can be assured of being
// 	 * able to power up successfully (see Battery Charging 1.2).
// 	 */
// 	__le32 dwWeakThreshold; /* in mWh */
// 	__le32 dwBatteryDesignCapacity; /* in mWh */
// 	__le32 dwBatteryLastFullchargeCapacity; /* in mWh */
// } __attribute__((packed));

// struct usb_pd_cap_consumer_port_descriptor {
// 	__u8 bLength;
// 	__u8 bDescriptorType;
// 	__u8 bDevCapabilityType;
// 	__u8 bReserved;
// 	__u8 bmCapabilities;
// /* port will oerate under: */
// #define USB_PD_CAP_CONSUMER_BC		(1 << 0) /* BC */
// #define USB_PD_CAP_CONSUMER_PD		(1 << 1) /* PD */
// #define USB_PD_CAP_CONSUMER_TYPE_C	(1 << 2) /* USB Type-C Current */
// 	__le16 wMinVoltage; /* in 50mV units */
// 	__le16 wMaxVoltage; /* in 50mV units */
// 	__u16 wReserved;
// 	__le32 dwMaxOperatingPower; /* in 10 mW - operating at steady state */
// 	__le32 dwMaxPeakPower; /* in 10mW units - operating at peak power */
// 	__le32 dwMaxPeakPowerTime; /* in 100ms units - duration of peak */
// #define USB_PD_CAP_CONSUMER_UNKNOWN_PEAK_POWER_TIME 0xffff
// } __attribute__((packed));

// struct usb_pd_cap_provider_port_descriptor {
// 	__u8 bLength;
// 	__u8 bDescriptorType;
// 	__u8 bDevCapabilityType;
// 	__u8 bReserved1;
// 	__u8 bmCapabilities;
// /* port will oerate under: */
// #define USB_PD_CAP_PROVIDER_BC		(1 << 0) /* BC */
// #define USB_PD_CAP_PROVIDER_PD		(1 << 1) /* PD */
// #define USB_PD_CAP_PROVIDER_TYPE_C	(1 << 2) /* USB Type-C Current */
// 	__u8 bNumOfPDObjects;
// 	__u8 bReserved2;
// 	__le32 wPowerDataObject[];
// } __attribute__((packed));

// /*
//  * Precision time measurement capability descriptor: advertised by devices and
//  * hubs that support PTM
//  */
// #define	USB_PTM_CAP_TYPE	0xb
// struct usb_ptm_cap_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;
// 	__u8  bDevCapabilityType;
// } __attribute__((packed));

// #define USB_DT_USB_PTM_ID_SIZE		3
// /*
//  * The size of the descriptor for the Sublink Speed Attribute Count
//  * (SSAC) specified in bmAttributes[4:0]. SSAC is zero-based
//  */
// #define USB_DT_USB_SSP_CAP_SIZE(ssac)	(12 + (ssac + 1) * 4)

// /*-------------------------------------------------------------------------*/

// /* USB_DT_WIRELESS_ENDPOINT_COMP:  companion descriptor associated with
//  * each endpoint descriptor for a wireless device
//  */
// struct usb_wireless_ep_comp_descriptor {
// 	__u8  bLength;
// 	__u8  bDescriptorType;

// 	__u8  bMaxBurst;
// 	__u8  bMaxSequence;
// 	__le16 wMaxStreamDelay;
// 	__le16 wOverTheAirPacketSize;
// 	__u8  bOverTheAirInterval;
// 	__u8  bmCompAttributes;
// #define USB_ENDPOINT_SWITCH_MASK	0x03	/* in bmCompAttributes */
// #define USB_ENDPOINT_SWITCH_NO		0
// #define USB_ENDPOINT_SWITCH_SWITCH	1
// #define USB_ENDPOINT_SWITCH_SCALE	2
// } __attribute__((packed));

// /*-------------------------------------------------------------------------*/

// /* USB_REQ_SET_HANDSHAKE is a four-way handshake used between a wireless
//  * host and a device for connection set up, mutual authentication, and
//  * exchanging short lived session keys.  The handshake depends on a CC.
//  */
// struct usb_handshake {
// 	__u8 bMessageNumber;
// 	__u8 bStatus;
// 	__u8 tTKID[3];
// 	__u8 bReserved;
// 	__u8 CDID[16];
// 	__u8 nonce[16];
// 	__u8 MIC[8];
// } __attribute__((packed));

// /*-------------------------------------------------------------------------*/

// /* USB_REQ_SET_CONNECTION modifies or revokes a connection context (CC).
//  * A CC may also be set up using non-wireless secure channels (including
//  * wired USB!), and some devices may support CCs with multiple hosts.
//  */
// struct usb_connection_context {
// 	__u8 CHID[16];		/* persistent host id */
// 	__u8 CDID[16];		/* device id (unique w/in host context) */
// 	__u8 CK[16];		/* connection key */
// } __attribute__((packed));

// /*-------------------------------------------------------------------------*/

// /* USB 2.0 defines three speeds, here's how Linux identifies them */

// enum usb_device_speed {
// 	USB_SPEED_UNKNOWN = 0,			/* enumerating */
// 	USB_SPEED_LOW, USB_SPEED_FULL,		/* usb 1.1 */
// 	USB_SPEED_HIGH,				/* usb 2.0 */
// 	USB_SPEED_WIRELESS,			/* wireless (usb 2.5) */
// 	USB_SPEED_SUPER,			/* usb 3.0 */
// 	USB_SPEED_SUPER_PLUS,			/* usb 3.1 */
// };

// enum usb_device_state {
// 	/* NOTATTACHED isn't in the USB spec, and this state acts
// 	 * the same as ATTACHED ... but it's clearer this way.
// 	 */
// 	USB_STATE_NOTATTACHED = 0,

// 	/* chapter 9 and authentication (wireless) device states */
// 	USB_STATE_ATTACHED,
// 	USB_STATE_POWERED,			/* wired */
// 	USB_STATE_RECONNECTING,			/* auth */
// 	USB_STATE_UNAUTHENTICATED,		/* auth */
// 	USB_STATE_DEFAULT,			/* limited function */
// 	USB_STATE_ADDRESS,
// 	USB_STATE_CONFIGURED,			/* most functions */

// 	USB_STATE_SUSPENDED

// 	/* NOTE:  there are actually four different SUSPENDED
// 	 * states, returning to POWERED, DEFAULT, ADDRESS, or
// 	 * CONFIGURED respectively when SOF tokens flow again.
// 	 * At this level there's no difference between L1 and L2
// 	 * suspend states.  (L2 being original USB 1.1 suspend.)
// 	 */
// };

// enum usb3_link_state {
// 	USB3_LPM_U0 = 0,
// 	USB3_LPM_U1,
// 	USB3_LPM_U2,
// 	USB3_LPM_U3
// };

// /*
//  * A U1 timeout of 0x0 means the parent hub will reject any transitions to U1.
//  * 0xff means the parent hub will accept transitions to U1, but will not
//  * initiate a transition.
//  *
//  * A U1 timeout of 0x1 to 0x7F also causes the hub to initiate a transition to
//  * U1 after that many microseconds.  Timeouts of 0x80 to 0xFE are reserved
//  * values.
//  *
//  * A U2 timeout of 0x0 means the parent hub will reject any transitions to U2.
//  * 0xff means the parent hub will accept transitions to U2, but will not
//  * initiate a transition.
//  *
//  * A U2 timeout of 0x1 to 0xFE also causes the hub to initiate a transition to
//  * U2 after N*256 microseconds.  Therefore a U2 timeout value of 0x1 means a U2
//  * idle timer of 256 microseconds, 0x2 means 512 microseconds, 0xFE means
//  * 65.024ms.
//  */
// #define USB3_LPM_DISABLED		0x0
// #define USB3_LPM_U1_MAX_TIMEOUT		0x7F
// #define USB3_LPM_U2_MAX_TIMEOUT		0xFE
// #define USB3_LPM_DEVICE_INITIATED	0xFF

// struct usb_set_sel_req {
// 	__u8	u1_sel;
// 	__u8	u1_pel;
// 	__le16	u2_sel;
// 	__le16	u2_pel;
// } __attribute__ ((packed));

// /*
//  * The Set System Exit Latency control transfer provides one byte each for
//  * U1 SEL and U1 PEL, so the max exit latency is 0xFF.  U2 SEL and U2 PEL each
//  * are two bytes long.
//  */
// #define USB3_LPM_MAX_U1_SEL_PEL		0xFF
// #define USB3_LPM_MAX_U2_SEL_PEL		0xFFFF

// /*-------------------------------------------------------------------------*/

// /*
//  * As per USB compliance update, a device that is actively drawing
//  * more than 100mA from USB must report itself as bus-powered in
//  * the GetStatus(DEVICE) call.
//  * https://compliance.usb.org/index.asp?UpdateFile=Electrical&Format=Standard#34
//  */
// #define USB_SELF_POWER_VBUS_MAX_DRAW		100

// #endif /* _UAPI__LINUX_USB_CH9_H */

// this how to implement a compiler assert and force the compiler to print a number
// if the assert fails by using a duplicate case label

const char *usbcore_name = "usbcore";

static bool nousb;

int usb_disabled(void)
{
	return nousb;
}

// delay in seconds
static int usb_autosuspend_delay = 2;
void usb_set_autosuspend_delay(int delay_in_seconds)
{
	usb_autosuspend_delay = delay_in_seconds;
}

static bool match_endpoint(struct usb_endpoint_descriptor *epd,
			   struct usb_endpoint_descriptor **bulk_in,
			   struct usb_endpoint_descriptor **bulk_out,
			   struct usb_endpoint_descriptor **int_in,
			   struct usb_endpoint_descriptor **int_out)
{
#if 0
	switch (usb_endpoint_type(epd)) {
	case USB_ENDPOINT_XFER_BULK:
		if (usb_endpoint_dir_in(epd)) {
			if (bulk_in && !*bulk_in) {
				*bulk_in = epd;
				break;
			}
		} else {
			if (bulk_out && !*bulk_out) {
				*bulk_out = epd;
				break;
			}
		}

		return false;
	case USB_ENDPOINT_XFER_INT:
		if (usb_endpoint_dir_in(epd)) {
			if (int_in && !*int_in) {
				*int_in = epd;
				break;
			}
		} else {
			if (int_out && !*int_out) {
				*int_out = epd;
				break;
			}
		}

		return false;
	default:
		return false;
	}

	return (!bulk_in || *bulk_in) && (!bulk_out || *bulk_out) &&
			(!int_in || *int_in) && (!int_out || *int_out);

#endif
	return true;
}
#if 0
/**
 * usb_find_common_endpoints() -- look up common endpoint descriptors
 * @alt:	alternate setting to search
 * @bulk_in:	pointer to descriptor pointer, or NULL
 * @bulk_out:	pointer to descriptor pointer, or NULL
 * @int_in:	pointer to descriptor pointer, or NULL
 * @int_out:	pointer to descriptor pointer, or NULL
 *
 * Search the alternate setting's endpoint descriptors for the first bulk-in,
 * bulk-out, interrupt-in and interrupt-out endpoints and return them in the
 * provided pointers (unless they are NULL).
 *
 * If a requested endpoint is not found, the corresponding pointer is set to
 * NULL.
 *
 * Return: Zero if all requested descriptors were found, or -ENXIO otherwise.
 */
int usb_find_common_endpoints(struct usb_host_interface *alt,
		struct usb_endpoint_descriptor **bulk_in,
		struct usb_endpoint_descriptor **bulk_out,
		struct usb_endpoint_descriptor **int_in,
		struct usb_endpoint_descriptor **int_out)
{
	struct usb_endpoint_descriptor *epd;
	int i;

	if (bulk_in)
		*bulk_in = NULL;
	if (bulk_out)
		*bulk_out = NULL;
	if (int_in)
		*int_in = NULL;
	if (int_out)
		*int_out = NULL;

	for (i = 0; i < alt->desc.bNumEndpoints; ++i) {
		epd = &alt->endpoint[i].desc;

		if (match_endpoint(epd, bulk_in, bulk_out, int_in, int_out))
			return 0;
	}

	return -ENXIO;
}
EXPORT_SYMBOL_GPL(usb_find_common_endpoints);

/**
 * usb_find_common_endpoints_reverse() -- look up common endpoint descriptors
 * @alt:	alternate setting to search
 * @bulk_in:	pointer to descriptor pointer, or NULL
 * @bulk_out:	pointer to descriptor pointer, or NULL
 * @int_in:	pointer to descriptor pointer, or NULL
 * @int_out:	pointer to descriptor pointer, or NULL
 *
 * Search the alternate setting's endpoint descriptors for the last bulk-in,
 * bulk-out, interrupt-in and interrupt-out endpoints and return them in the
 * provided pointers (unless they are NULL).
 *
 * If a requested endpoint is not found, the corresponding pointer is set to
 * NULL.
 *
 * Return: Zero if all requested descriptors were found, or -ENXIO otherwise.
 */
int usb_find_common_endpoints_reverse(struct usb_host_interface *alt,
		struct usb_endpoint_descriptor **bulk_in,
		struct usb_endpoint_descriptor **bulk_out,
		struct usb_endpoint_descriptor **int_in,
		struct usb_endpoint_descriptor **int_out)
{
	struct usb_endpoint_descriptor *epd;
	int i;

	if (bulk_in)
		*bulk_in = NULL;
	if (bulk_out)
		*bulk_out = NULL;
	if (int_in)
		*int_in = NULL;
	if (int_out)
		*int_out = NULL;

	for (i = alt->desc.bNumEndpoints - 1; i >= 0; --i) {
		epd = &alt->endpoint[i].desc;

		if (match_endpoint(epd, bulk_in, bulk_out, int_in, int_out))
			return 0;
	}

	return -ENXIO;
}
EXPORT_SYMBOL_GPL(usb_find_common_endpoints_reverse);

/**
 * usb_find_alt_setting() - Given a configuration, find the alternate setting
 * for the given interface.
 * @config: the configuration to search (not necessarily the current config).
 * @iface_num: interface number to search in
 * @alt_num: alternate interface setting number to search for.
 *
 * Search the configuration's interface cache for the given alt setting.
 *
 * Return: The alternate setting, if found. %NULL otherwise.
 */
struct usb_host_interface *usb_find_alt_setting(
		struct usb_host_config *config,
		unsigned int iface_num,
		unsigned int alt_num)
{
	struct usb_interface_cache *intf_cache = NULL;
	int i;

	if (!config)
		return NULL;
	for (i = 0; i < config->desc.bNumInterfaces; i++) {
		if (config->intf_cache[i]->altsetting[0].desc.bInterfaceNumber
				== iface_num) {
			intf_cache = config->intf_cache[i];
			break;
		}
	}
	if (!intf_cache)
		return NULL;
	for (i = 0; i < intf_cache->num_altsetting; i++)
		if (intf_cache->altsetting[i].desc.bAlternateSetting == alt_num)
			return &intf_cache->altsetting[i];

	printk(KERN_DEBUG "Did not find alt setting %u for intf %u, "
			"config %u\n", alt_num, iface_num,
			config->desc.bConfigurationValue);
	return NULL;
}
EXPORT_SYMBOL_GPL(usb_find_alt_setting);

/**
 * usb_ifnum_to_if - get the interface object with a given interface number
 * @dev: the device whose current configuration is considered
 * @ifnum: the desired interface
 *
 * This walks the device descriptor for the currently active configuration
 * to find the interface object with the particular interface number.
 *
 * Note that configuration descriptors are not required to assign interface
 * numbers sequentially, so that it would be incorrect to assume that
 * the first interface in that descriptor corresponds to interface zero.
 * This routine helps device drivers avoid such mistakes.
 * However, you should make sure that you do the right thing with any
 * alternate settings available for this interfaces.
 *
 * Don't call this function unless you are bound to one of the interfaces
 * on this device or you have locked the device!
 *
 * Return: A pointer to the interface that has @ifnum as interface number,
 * if found. %NULL otherwise.
 */
struct usb_interface *usb_ifnum_to_if(const struct usb_device *dev,
				      unsigned ifnum)
{
	struct usb_host_config *config = dev->actconfig;
	int i;

	if (!config)
		return NULL;
	for (i = 0; i < config->desc.bNumInterfaces; i++)
		if (config->interface[i]->altsetting[0]
				.desc.bInterfaceNumber == ifnum)
			return config->interface[i];

	return NULL;
}
EXPORT_SYMBOL_GPL(usb_ifnum_to_if);

/**
 * usb_altnum_to_altsetting - get the altsetting structure with a given alternate setting number.
 * @intf: the interface containing the altsetting in question
 * @altnum: the desired alternate setting number
 *
 * This searches the altsetting array of the specified interface for
 * an entry with the correct bAlternateSetting value.
 *
 * Note that altsettings need not be stored sequentially by number, so
 * it would be incorrect to assume that the first altsetting entry in
 * the array corresponds to altsetting zero.  This routine helps device
 * drivers avoid such mistakes.
 *
 * Don't call this function unless you are bound to the intf interface
 * or you have locked the device!
 *
 * Return: A pointer to the entry of the altsetting array of @intf that
 * has @altnum as the alternate setting number. %NULL if not found.
 */
struct usb_host_interface *usb_altnum_to_altsetting(
					const struct usb_interface *intf,
					unsigned int altnum)
{
	int i;

	for (i = 0; i < intf->num_altsetting; i++) {
		if (intf->altsetting[i].desc.bAlternateSetting == altnum)
			return &intf->altsetting[i];
	}
	return NULL;
}
EXPORT_SYMBOL_GPL(usb_altnum_to_altsetting);

struct find_interface_arg {
	int minor;
	struct device_driver *drv;
};

static int __find_interface(struct device *dev, const void *data)
{
	const struct find_interface_arg *arg = data;
	struct usb_interface *intf;

	if (!is_usb_interface(dev))
		return 0;

	if (dev->driver != arg->drv)
		return 0;
	intf = to_usb_interface(dev);
	return intf->minor == arg->minor;
}

/**
 * usb_find_interface - find usb_interface pointer for driver and device
 * @drv: the driver whose current configuration is considered
 * @minor: the minor number of the desired device
 *
 * This walks the bus device list and returns a pointer to the interface
 * with the matching minor and driver.  Note, this only works for devices
 * that share the USB major number.
 *
 * Return: A pointer to the interface with the matching major and @minor.
 */
struct usb_interface *usb_find_interface(struct usb_driver *drv, int minor)
{
	struct find_interface_arg argb;
	struct device *dev;

	argb.minor = minor;
	argb.drv = &drv->drvwrap.driver;

	dev = bus_find_device(&usb_bus_type, NULL, &argb, __find_interface);

	/* Drop reference count from bus_find_device */
	put_device(dev);

	return dev ? to_usb_interface(dev) : NULL;
}
EXPORT_SYMBOL_GPL(usb_find_interface);

struct each_dev_arg {
	void *data;
	int (*fn)(struct usb_device *, void *);
};

static int __each_dev(struct device *dev, void *data)
{
	struct each_dev_arg *arg = (struct each_dev_arg *)data;

	/* There are struct usb_interface on the same bus, filter them out */
	if (!is_usb_device(dev))
		return 0;

	return arg->fn(to_usb_device(dev), arg->data);
}

/**
 * usb_for_each_dev - iterate over all USB devices in the system
 * @data: data pointer that will be handed to the callback function
 * @fn: callback function to be called for each USB device
 *
 * Iterate over all USB devices and call @fn for each, passing it @data. If it
 * returns anything other than 0, we break the iteration prematurely and return
 * that value.
 */
int usb_for_each_dev(void *data, int (*fn)(struct usb_device *, void *))
{
	struct each_dev_arg arg = {data, fn};

	return bus_for_each_dev(&usb_bus_type, NULL, &arg, __each_dev);
}
EXPORT_SYMBOL_GPL(usb_for_each_dev);

/**
 * usb_release_dev - free a usb device structure when all users of it are finished.
 * @dev: device that's been disconnected
 *
 * Will be called only by the device core when all users of this usb device are
 * done.
 */
static void usb_release_dev(struct device *dev)
{
	struct usb_device *udev;
	struct usb_hcd *hcd;

	udev = to_usb_device(dev);
	hcd = bus_to_hcd(udev->bus);

	usb_destroy_configuration(udev);
	usb_release_bos_descriptor(udev);
	of_node_put(dev->of_node);
	usb_put_hcd(hcd);
	kfree(udev->product);
	kfree(udev->manufacturer);
	kfree(udev->serial);
	kfree(udev);
}

static int usb_dev_uevent(struct device *dev, struct kobj_uevent_env *env)
{
	struct usb_device *usb_dev;

	usb_dev = to_usb_device(dev);

	if (add_uevent_var(env, "BUSNUM=%03d", usb_dev->bus->busnum))
		return -ENOMEM;

	if (add_uevent_var(env, "DEVNUM=%03d", usb_dev->devnum))
		return -ENOMEM;

	return 0;
}

#ifdef CONFIG_PM

/* USB device Power-Management thunks.
 * There's no need to distinguish here between quiescing a USB device
 * and powering it down; the generic_suspend() routine takes care of
 * it by skipping the usb_port_suspend() call for a quiesce.  And for
 * USB interfaces there's no difference at all.
 */

static int usb_dev_prepare(struct device *dev)
{
	return 0;		/* Implement eventually? */
}

static void usb_dev_complete(struct device *dev)
{
	/* Currently used only for rebinding interfaces */
	usb_resume_complete(dev);
}

static int usb_dev_suspend(struct device *dev)
{
	return usb_suspend(dev, PMSG_SUSPEND);
}

static int usb_dev_resume(struct device *dev)
{
	return usb_resume(dev, PMSG_RESUME);
}

static int usb_dev_freeze(struct device *dev)
{
	return usb_suspend(dev, PMSG_FREEZE);
}

static int usb_dev_thaw(struct device *dev)
{
	return usb_resume(dev, PMSG_THAW);
}

static int usb_dev_poweroff(struct device *dev)
{
	return usb_suspend(dev, PMSG_HIBERNATE);
}

static int usb_dev_restore(struct device *dev)
{
	return usb_resume(dev, PMSG_RESTORE);
}

static const struct dev_pm_ops usb_device_pm_ops = {
	.prepare =	usb_dev_prepare,
	.complete =	usb_dev_complete,
	.suspend =	usb_dev_suspend,
	.resume =	usb_dev_resume,
	.freeze =	usb_dev_freeze,
	.thaw =		usb_dev_thaw,
	.poweroff =	usb_dev_poweroff,
	.restore =	usb_dev_restore,
	.runtime_suspend =	usb_runtime_suspend,
	.runtime_resume =	usb_runtime_resume,
	.runtime_idle =		usb_runtime_idle,
};

#endif /* CONFIG_PM */


static char *usb_devnode(struct device *dev,
			 umode_t *mode, kuid_t *uid, kgid_t *gid)
{
	struct usb_device *usb_dev;

	usb_dev = to_usb_device(dev);
	return kasprintf(GFP_KERNEL, "bus/usb/%03d/%03d",
			 usb_dev->bus->busnum, usb_dev->devnum);
}

struct device_type usb_device_type = {
	.name =		"usb_device",
	.release =	usb_release_dev,
	.uevent =	usb_dev_uevent,
	.devnode = 	usb_devnode,
#ifdef CONFIG_PM
	.pm =		&usb_device_pm_ops,
#endif
};


/* Returns 1 if @usb_bus is WUSB, 0 otherwise */
static unsigned usb_bus_is_wusb(struct usb_bus *bus)
{
	struct usb_hcd *hcd = bus_to_hcd(bus);
	return hcd->wireless;
}

static bool usb_dev_authorized(struct usb_device *dev, struct usb_hcd *hcd)
{
	struct usb_hub *hub;

	if (!dev->parent)
		return true; /* Root hub always ok [and always wired] */

	switch (hcd->dev_policy) {
	case USB_DEVICE_AUTHORIZE_NONE:
	default:
		return false;

	case USB_DEVICE_AUTHORIZE_ALL:
		return true;

	case USB_DEVICE_AUTHORIZE_INTERNAL:
		hub = usb_hub_to_struct_hub(dev->parent);
		return hub->ports[dev->portnum - 1]->connect_type ==
				USB_PORT_CONNECT_TYPE_HARD_WIRED;
	}
}

/**
 * usb_alloc_dev - usb device constructor (usbcore-internal)
 * @parent: hub to which device is connected; null to allocate a root hub
 * @bus: bus used to access the device
 * @port1: one-based index of port; ignored for root hubs
 *
 * Context: task context, might sleep.
 *
 * Only hub drivers (including virtual root hub drivers for host
 * controllers) should ever call this.
 *
 * This call may not be used in a non-sleeping context.
 *
 * Return: On success, a pointer to the allocated usb device. %NULL on
 * failure.
 */
struct usb_device *usb_alloc_dev(struct usb_device *parent,
				 struct usb_bus *bus, unsigned port1)
{
	struct usb_device *dev;
	struct usb_hcd *usb_hcd = bus_to_hcd(bus);
	unsigned root_hub = 0;
	unsigned raw_port = port1;

	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return NULL;

	if (!usb_get_hcd(usb_hcd)) {
		kfree(dev);
		return NULL;
	}
	/* Root hubs aren't true devices, so don't allocate HCD resources */
	if (usb_hcd->driver->alloc_dev && parent &&
		!usb_hcd->driver->alloc_dev(usb_hcd, dev)) {
		usb_put_hcd(bus_to_hcd(bus));
		kfree(dev);
		return NULL;
	}

	device_initialize(&dev->dev);
	dev->dev.bus = &usb_bus_type;
	dev->dev.type = &usb_device_type;
	dev->dev.groups = usb_device_groups;
	set_dev_node(&dev->dev, dev_to_node(bus->sysdev));
	dev->state = USB_STATE_ATTACHED;
	dev->lpm_disable_count = 1;
	atomic_set(&dev->urbnum, 0);

	INIT_LIST_HEAD(&dev->ep0.urb_list);
	dev->ep0.desc.bLength = USB_DT_ENDPOINT_SIZE;
	dev->ep0.desc.bDescriptorType = USB_DT_ENDPOINT;
	/* ep0 maxpacket comes later, from device descriptor */
	usb_enable_endpoint(dev, &dev->ep0, false);
	dev->can_submit = 1;

	/* Save readable and stable topology id, distinguishing devices
	 * by location for diagnostics, tools, driver model, etc.  The
	 * string is a path along hub ports, from the root.  Each device's
	 * dev->devpath will be stable until USB is re-cabled, and hubs
	 * are often labeled with these port numbers.  The name isn't
	 * as stable:  bus->busnum changes easily from modprobe order,
	 * cardbus or pci hotplugging, and so on.
	 */
	if (unlikely(!parent)) {
		dev->devpath[0] = '0';
		dev->route = 0;

		dev->dev.parent = bus->controller;
		device_set_of_node_from_dev(&dev->dev, bus->sysdev);
		dev_set_name(&dev->dev, "usb%d", bus->busnum);
		root_hub = 1;
	} else {
		/* match any labeling on the hubs; it's one-based */
		if (parent->devpath[0] == '0') {
			snprintf(dev->devpath, sizeof dev->devpath,
				"%d", port1);
			/* Root ports are not counted in route string */
			dev->route = 0;
		} else {
			snprintf(dev->devpath, sizeof dev->devpath,
				"%s.%d", parent->devpath, port1);
			/* Route string assumes hubs have less than 16 ports */
			if (port1 < 15)
				dev->route = parent->route +
					(port1 << ((parent->level - 1)*4));
			else
				dev->route = parent->route +
					(15 << ((parent->level - 1)*4));
		}

		dev->dev.parent = &parent->dev;
		dev_set_name(&dev->dev, "%d-%s", bus->busnum, dev->devpath);

		if (!parent->parent) {
			/* device under root hub's port */
			raw_port = usb_hcd_find_raw_port_number(usb_hcd,
				port1);
		}
		dev->dev.of_node = usb_of_get_device_node(parent, raw_port);

		/* hub driver sets up TT records */
	}

	dev->portnum = port1;
	dev->bus = bus;
	dev->parent = parent;
	INIT_LIST_HEAD(&dev->filelist);

#ifdef CONFIG_PM
	pm_runtime_set_autosuspend_delay(&dev->dev,
			usb_autosuspend_delay * 1000);
	dev->connect_time = jiffies;
	dev->active_duration = -jiffies;
#endif

	dev->authorized = usb_dev_authorized(dev, usb_hcd);
	if (!root_hub)
		dev->wusb = usb_bus_is_wusb(bus) ? 1 : 0;

	return dev;
}
EXPORT_SYMBOL_GPL(usb_alloc_dev);

/**
 * usb_get_dev - increments the reference count of the usb device structure
 * @dev: the device being referenced
 *
 * Each live reference to a device should be refcounted.
 *
 * Drivers for USB interfaces should normally record such references in
 * their probe() methods, when they bind to an interface, and release
 * them by calling usb_put_dev(), in their disconnect() methods.
 * However, if a driver does not access the usb_device structure after
 * its disconnect() method returns then refcounting is not necessary,
 * because the USB core guarantees that a usb_device will not be
 * deallocated until after all of its interface drivers have been unbound.
 *
 * Return: A pointer to the device with the incremented reference counter.
 */
struct usb_device *usb_get_dev(struct usb_device *dev)
{
	if (dev)
		get_device(&dev->dev);
	return dev;
}
EXPORT_SYMBOL_GPL(usb_get_dev);

/**
 * usb_put_dev - release a use of the usb device structure
 * @dev: device that's been disconnected
 *
 * Must be called when a user of a device is finished with it.  When the last
 * user of the device calls this function, the memory of the device is freed.
 */
void usb_put_dev(struct usb_device *dev)
{
	if (dev)
		put_device(&dev->dev);
}
EXPORT_SYMBOL_GPL(usb_put_dev);

/**
 * usb_get_intf - increments the reference count of the usb interface structure
 * @intf: the interface being referenced
 *
 * Each live reference to a interface must be refcounted.
 *
 * Drivers for USB interfaces should normally record such references in
 * their probe() methods, when they bind to an interface, and release
 * them by calling usb_put_intf(), in their disconnect() methods.
 * However, if a driver does not access the usb_interface structure after
 * its disconnect() method returns then refcounting is not necessary,
 * because the USB core guarantees that a usb_interface will not be
 * deallocated until after its driver has been unbound.
 *
 * Return: A pointer to the interface with the incremented reference counter.
 */
struct usb_interface *usb_get_intf(struct usb_interface *intf)
{
	if (intf)
		get_device(&intf->dev);
	return intf;
}
EXPORT_SYMBOL_GPL(usb_get_intf);

/**
 * usb_put_intf - release a use of the usb interface structure
 * @intf: interface that's been decremented
 *
 * Must be called when a user of an interface is finished with it.  When the
 * last user of the interface calls this function, the memory of the interface
 * is freed.
 */
void usb_put_intf(struct usb_interface *intf)
{
	if (intf)
		put_device(&intf->dev);
}
EXPORT_SYMBOL_GPL(usb_put_intf);

/**
 * usb_intf_get_dma_device - acquire a reference on the usb interface's DMA endpoint
 * @intf: the usb interface
 *
 * While a USB device cannot perform DMA operations by itself, many USB
 * controllers can. A call to usb_intf_get_dma_device() returns the DMA endpoint
 * for the given USB interface, if any. The returned device structure must be
 * released with put_device().
 *
 * See also usb_get_dma_device().
 *
 * Returns: A reference to the usb interface's DMA endpoint; or NULL if none
 *          exists.
 */
struct device *usb_intf_get_dma_device(struct usb_interface *intf)
{
	struct usb_device *udev = interface_to_usbdev(intf);
	struct device *dmadev;

	if (!udev->bus)
		return NULL;

	dmadev = get_device(udev->bus->sysdev);
	if (!dmadev || !dmadev->dma_mask) {
		put_device(dmadev);
		return NULL;
	}

	return dmadev;
}
EXPORT_SYMBOL_GPL(usb_intf_get_dma_device);

/*			USB device locking
 *
 * USB devices and interfaces are locked using the semaphore in their
 * embedded struct device.  The hub driver guarantees that whenever a
 * device is connected or disconnected, drivers are called with the
 * USB device locked as well as their particular interface.
 *
 * Complications arise when several devices are to be locked at the same
 * time.  Only hub-aware drivers that are part of usbcore ever have to
 * do this; nobody else needs to worry about it.  The rule for locking
 * is simple:
 *
 *	When locking both a device and its parent, always lock the
 *	parent first.
 */

/**
 * usb_lock_device_for_reset - cautiously acquire the lock for a usb device structure
 * @udev: device that's being locked
 * @iface: interface bound to the driver making the request (optional)
 *
 * Attempts to acquire the device lock, but fails if the device is
 * NOTATTACHED or SUSPENDED, or if iface is specified and the interface
 * is neither BINDING nor BOUND.  Rather than sleeping to wait for the
 * lock, the routine polls repeatedly.  This is to prevent deadlock with
 * disconnect; in some drivers (such as usb-storage) the disconnect()
 * or suspend() method will block waiting for a device reset to complete.
 *
 * Return: A negative error code for failure, otherwise 0.
 */
int usb_lock_device_for_reset(struct usb_device *udev,
			      const struct usb_interface *iface)
{
	unsigned long jiffies_expire = jiffies + HZ;

	if (udev->state == USB_STATE_NOTATTACHED)
		return -ENODEV;
	if (udev->state == USB_STATE_SUSPENDED)
		return -EHOSTUNREACH;
	if (iface && (iface->condition == USB_INTERFACE_UNBINDING ||
			iface->condition == USB_INTERFACE_UNBOUND))
		return -EINTR;

	while (!usb_trylock_device(udev)) {

		/* If we can't acquire the lock after waiting one second,
		 * we're probably deadlocked */
		if (time_after(jiffies, jiffies_expire))
			return -EBUSY;

		msleep(15);
		if (udev->state == USB_STATE_NOTATTACHED)
			return -ENODEV;
		if (udev->state == USB_STATE_SUSPENDED)
			return -EHOSTUNREACH;
		if (iface && (iface->condition == USB_INTERFACE_UNBINDING ||
				iface->condition == USB_INTERFACE_UNBOUND))
			return -EINTR;
	}
	return 0;
}
EXPORT_SYMBOL_GPL(usb_lock_device_for_reset);

/**
 * usb_get_current_frame_number - return current bus frame number
 * @dev: the device whose bus is being queried
 *
 * Return: The current frame number for the USB host controller used
 * with the given USB device. This can be used when scheduling
 * isochronous requests.
 *
 * Note: Different kinds of host controller have different "scheduling
 * horizons". While one type might support scheduling only 32 frames
 * into the future, others could support scheduling up to 1024 frames
 * into the future.
 *
 */
int usb_get_current_frame_number(struct usb_device *dev)
{
	return usb_hcd_get_frame_number(dev);
}
EXPORT_SYMBOL_GPL(usb_get_current_frame_number);

/*-------------------------------------------------------------------*/
/*
 * __usb_get_extra_descriptor() finds a descriptor of specific type in the
 * extra field of the interface and endpoint descriptor structs.
 */

int __usb_get_extra_descriptor(char *buffer, unsigned size,
			       unsigned char type, void **ptr, size_t minsize)
{
	struct usb_descriptor_header *header;

	while (size >= sizeof(struct usb_descriptor_header)) {
		header = (struct usb_descriptor_header *)buffer;

		if (header->bLength < 2 || header->bLength > size) {
			printk(KERN_ERR
				"%s: bogus descriptor, type %d length %d\n",
				usbcore_name,
				header->bDescriptorType,
				header->bLength);
			return -1;
		}

		if (header->bDescriptorType == type && header->bLength >= minsize) {
			*ptr = header;
			return 0;
		}

		buffer += header->bLength;
		size -= header->bLength;
	}
	return -1;
}
EXPORT_SYMBOL_GPL(__usb_get_extra_descriptor);

/**
 * usb_alloc_coherent - allocate dma-consistent buffer for URB_NO_xxx_DMA_MAP
 * @dev: device the buffer will be used with
 * @size: requested buffer size
 * @mem_flags: affect whether allocation may block
 * @dma: used to return DMA address of buffer
 *
 * Return: Either null (indicating no buffer could be allocated), or the
 * cpu-space pointer to a buffer that may be used to perform DMA to the
 * specified device.  Such cpu-space buffers are returned along with the DMA
 * address (through the pointer provided).
 *
 * Note:
 * These buffers are used with URB_NO_xxx_DMA_MAP set in urb->transfer_flags
 * to avoid behaviors like using "DMA bounce buffers", or thrashing IOMMU
 * hardware during URB completion/resubmit.  The implementation varies between
 * platforms, depending on details of how DMA will work to this device.
 * Using these buffers also eliminates cacheline sharing problems on
 * architectures where CPU caches are not DMA-coherent.  On systems without
 * bus-snooping caches, these buffers are uncached.
 *
 * When the buffer is no longer used, free it with usb_free_coherent().
 */
void *usb_alloc_coherent(struct usb_device *dev, size_t size, gfp_t mem_flags,
			 dma_addr_t *dma)
{
	if (!dev || !dev->bus)
		return NULL;
	return hcd_buffer_alloc(dev->bus, size, mem_flags, dma);
}
EXPORT_SYMBOL_GPL(usb_alloc_coherent);

/**
 * usb_free_coherent - free memory allocated with usb_alloc_coherent()
 * @dev: device the buffer was used with
 * @size: requested buffer size
 * @addr: CPU address of buffer
 * @dma: DMA address of buffer
 *
 * This reclaims an I/O buffer, letting it be reused.  The memory must have
 * been allocated using usb_alloc_coherent(), and the parameters must match
 * those provided in that allocation request.
 */
void usb_free_coherent(struct usb_device *dev, size_t size, void *addr,
		       dma_addr_t dma)
{
	if (!dev || !dev->bus)
		return;
	if (!addr)
		return;
	hcd_buffer_free(dev->bus, size, addr, dma);
}
EXPORT_SYMBOL_GPL(usb_free_coherent);

/*
 * Notifications of device and interface registration
 */
static int usb_bus_notify(struct notifier_block *nb, unsigned long action,
		void *data)
{
	struct device *dev = data;

	switch (action) {
	case BUS_NOTIFY_ADD_DEVICE:
		if (dev->type == &usb_device_type)
			(void) usb_create_sysfs_dev_files(to_usb_device(dev));
		else if (dev->type == &usb_if_device_type)
			usb_create_sysfs_intf_files(to_usb_interface(dev));
		break;

	case BUS_NOTIFY_DEL_DEVICE:
		if (dev->type == &usb_device_type)
			usb_remove_sysfs_dev_files(to_usb_device(dev));
		else if (dev->type == &usb_if_device_type)
			usb_remove_sysfs_intf_files(to_usb_interface(dev));
		break;
	}
	return 0;
}

static struct notifier_block usb_bus_nb = {
	.notifier_call = usb_bus_notify,
};

static void usb_debugfs_init(void)
{
	debugfs_create_file("devices", 0444, usb_debug_root, NULL,
			    &usbfs_devices_fops);
}

static void usb_debugfs_cleanup(void)
{
	debugfs_remove(debugfs_lookup("devices", usb_debug_root));
}

/*
 * Init
 */
static int __init usb_init(void)
{
	int retval;
	if (usb_disabled()) {
		pr_info("%s: USB support disabled\n", usbcore_name);
		return 0;
	}
	usb_init_pool_max();

	usb_debugfs_init();

	usb_acpi_register();
	retval = bus_register(&usb_bus_type);
	if (retval)
		goto bus_register_failed;
	retval = bus_register_notifier(&usb_bus_type, &usb_bus_nb);
	if (retval)
		goto bus_notifier_failed;
	retval = usb_major_init();
	if (retval)
		goto major_init_failed;
	retval = usb_register(&usbfs_driver);
	if (retval)
		goto driver_register_failed;
	retval = usb_devio_init();
	if (retval)
		goto usb_devio_init_failed;
	retval = usb_hub_init();
	if (retval)
		goto hub_init_failed;
	retval = usb_register_device_driver(&usb_generic_driver, THIS_MODULE);
	if (!retval)
		goto out;

	usb_hub_cleanup();
hub_init_failed:
	usb_devio_cleanup();
usb_devio_init_failed:
	usb_deregister(&usbfs_driver);
driver_register_failed:
	usb_major_cleanup();
major_init_failed:
	bus_unregister_notifier(&usb_bus_type, &usb_bus_nb);
bus_notifier_failed:
	bus_unregister(&usb_bus_type);
bus_register_failed:
	usb_acpi_unregister();
	usb_debugfs_cleanup();
out:
	return retval;
}

/*
 * Cleanup
 */
static void __exit usb_exit(void)
{
	/* This will matter if shutdown/reboot does exitcalls. */
	if (usb_disabled())
		return;

	usb_release_quirk_list();
	usb_deregister_device_driver(&usb_generic_driver);
	usb_major_cleanup();
	usb_deregister(&usbfs_driver);
	usb_devio_cleanup();
	usb_hub_cleanup();
	bus_unregister_notifier(&usb_bus_type, &usb_bus_nb);
	bus_unregister(&usb_bus_type);
	usb_acpi_unregister();
	usb_debugfs_cleanup();
	idr_destroy(&usb_bus_idr);
}

subsys_initcall(usb_init);
module_exit(usb_exit);
MODULE_LICENSE("GPL");
#endif
int main(int argc, char *argv[])
{
	compiler_assert_nr_func(sizeof(int) == 4, sizeof(int), main_c);
	return 0;
}
