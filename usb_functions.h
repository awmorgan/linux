File drivers/usb/cdns3/cdns3-plat.c:
331:	static void cdns3_driver_exit(void);
331:	static int cdns3_driver_init(void);
52:	static int cdns3_plat_probe(struct platform_device *);
178:	static int cdns3_plat_remove(struct platform_device *);
40:	static void set_phy_power_off(struct cdns *);
25:	static int set_phy_power_on(struct cdns *);

File drivers/usb/cdns3/cdns3-ti.c:
231:	static void cdns_ti_driver_exit(void);
231:	static int cdns_ti_driver_init(void);
87:	static int cdns_ti_probe(struct platform_device *);
202:	static int cdns_ti_remove(struct platform_device *);
193:	static int cdns_ti_remove_core(struct device *, void *);

File drivers/usb/cdns3/core.c:
297:	int cdns_hw_role_switch(struct cdns *);
427:	int cdns_init(struct cdns *);
497:	int cdns_remove(struct cdns *);
262:	static int cdns_idle_role_start(struct cdns *);
267:	static void cdns_idle_role_stop(struct cdns *);
341:	static enum usb_role cdns_role_get(struct usb_role_switch *);
357:	static int cdns_role_set(struct usb_role_switch *, enum usb_role);
28:	static int cdns_role_start(struct cdns *, enum usb_role);
405:	static irqreturn_t cdns_wakeup_irq(int, void *);

File drivers/usb/cdns3/drd.c:
106:	void cdns_clear_vbus(struct cdns *);
475:	int cdns_drd_exit(struct cdns *);
260:	void cdns_drd_gadget_off(struct cdns *);
228:	int cdns_drd_gadget_on(struct cdns *);
207:	void cdns_drd_host_off(struct cdns *);
178:	int cdns_drd_host_on(struct cdns *);
384:	int cdns_drd_init(struct cdns *);
309:	int cdns_drd_update_mode(struct cdns *);
86:	int cdns_get_id(struct cdns *);
96:	int cdns_get_vbus(struct cdns *);
142:	bool cdns_is_device(struct cdns *);
132:	bool cdns_is_host(struct cdns *);
484:	bool cdns_power_is_lost(struct cdns *);
119:	void cdns_set_vbus(struct cdns *);
349:	static irqreturn_t cdns_drd_irq(int, void *);
332:	static irqreturn_t cdns_drd_thread_irq(int, void *);

File drivers/usb/cdns3/gadget-export.h:
30:	static int cdns3_gadget_init(struct cdns *);

File drivers/usb/cdns3/host.c:
127:	int cdns_host_init(struct cdns *);
60:	static int __cdns_host_init(struct cdns *);
119:	static void cdns_host_exit(struct cdns *);
27:	static void xhci_cdns3_plat_start(struct usb_hcd *);
48:	static int xhci_cdns3_resume_quirk(struct usb_hcd *);

File drivers/usb/common/common.c:
276:	enum usb_dr_mode of_usb_get_dr_mode_by_phy(struct device_node *, int);
328:	bool of_usb_host_tpl_support(struct device_node *);
342:	int of_usb_update_otg_caps(struct device_node *, struct usb_otg_caps *);
231:	unsigned int usb_decode_interval(const struct usb_endpoint_descriptor *, enum usb_device_speed);
34:	const char *usb_ep_type_string(int);
190:	enum usb_dr_mode usb_get_dr_mode(struct device *);
107:	enum usb_device_speed usb_get_maximum_speed(struct device *);
134:	enum usb_ssp_rate usb_get_maximum_ssp_rate(struct device *);
210:	enum usb_dr_mode usb_get_role_switch_default_mode(struct device *);
400:	struct device *usb_of_get_companion_dev(struct device *);
43:	const char *usb_otg_state_string(enum usb_otg_state);
91:	const char *usb_speed_string(enum usb_device_speed);
154:	const char *usb_state_string(enum usb_device_state);
426:	static void usb_common_exit(void);
419:	static int usb_common_init(void);

File drivers/usb/core/buffer.c:
115:	void *hcd_buffer_alloc(struct usb_bus *, size_t, gfp_t, dma_addr_t *);
65:	int hcd_buffer_create(struct usb_hcd *);
97:	void hcd_buffer_destroy(struct usb_hcd *);
144:	void hcd_buffer_free(struct usb_bus *, size_t, void *, dma_addr_t);
33:	void usb_init_pool_max(void);

File drivers/usb/core/config.c:
825:	void usb_destroy_configuration(struct usb_device *);
978:	int usb_get_bos_descriptor(struct usb_device *);
861:	int usb_get_configuration(struct usb_device *);
959:	void usb_release_bos_descriptor(struct usb_device *);
484:	void usb_release_interface_cache(struct kref *);

File drivers/usb/core/devices.c:
390:	static ssize_t usb_device_dump(char **, size_t *, loff_t *, loff_t *, struct usb_device *, struct usb_bus *, int, int, int);
510:	static ssize_t usb_device_read(struct file *, char *, size_t, loff_t *);

File drivers/usb/core/devio.c:
2906:	void usb_devio_cleanup(void);
2880:	int usb_devio_init(void);
748:	void usbfs_notify_resume(struct usb_device *);
743:	void usbfs_notify_suspend(struct usb_device *);
613:	static void async_completed(struct urb *);
869:	static int check_ctrlrecip(struct usb_dev_state *, unsigned int, unsigned int, unsigned int);
770:	static int claimintf(struct usb_dev_state *, unsigned int);
186:	static void dec_usb_memory_use_count(struct usb_memory *, int *);
653:	static void destroy_async(struct usb_dev_state *, struct list_head *);
707:	static void driver_disconnect(struct usb_interface *);
701:	static int driver_probe(struct usb_interface *, const struct usb_device_id *);
737:	static int driver_resume(struct usb_interface *);
732:	static int driver_suspend(struct usb_interface *, pm_message_t);
406:	static void free_async(struct async *);
937:	static int parse_usbdevfs_streams(struct usb_dev_state *, struct usbdevfs_streams *, unsigned int *, unsigned int *, struct usb_host_endpoint ***, struct usb_interface **);
2031:	static int processcompl(struct async *, void **);
524:	static void snoop_urb_data(struct urb *, unsigned int);
2802:	static long usbdev_ioctl(struct file *, unsigned int, unsigned long);
229:	static int usbdev_mmap(struct file *, struct vm_area_struct *);
2861:	static int usbdev_notify(struct notifier_block *, unsigned long, void *);
1023:	static int usbdev_open(struct inode *, struct file *);
2813:	static __poll_t usbdev_poll(struct file *, struct poll_table_struct *);
301:	static ssize_t usbdev_read(struct file *, char *, size_t, loff_t *);
1080:	static int usbdev_release(struct inode *, struct file *);
217:	static void usbdev_vm_close(struct vm_area_struct *);
207:	static void usbdev_vm_open(struct vm_area_struct *);
1118:	static void usbfs_blocking_completion(struct urb *);

File drivers/usb/core/driver.c:
1096:	void usb_deregister(struct usb_driver *);
1018:	void usb_deregister_device_driver(struct usb_device_driver *);
824:	const struct usb_device_id *usb_device_match_id(struct usb_device *, const struct usb_device_id *);
839:	bool usb_driver_applicable(struct usb_device *, struct usb_device_driver *);
535:	int usb_driver_claim_interface(struct usb_driver *, struct usb_interface *, void *);
609:	void usb_driver_release_interface(struct usb_driver *, struct usb_interface *);
1113:	void usb_forced_unbind_intf(struct usb_interface *);
638:	int usb_match_device(struct usb_device *, const struct usb_device_id *);
802:	const struct usb_device_id *usb_match_id(struct usb_interface *, const struct usb_device_id *);
709:	int usb_match_one_id(struct usb_interface *, const struct usb_device_id *);
674:	int usb_match_one_id_intf(struct usb_device *, struct usb_host_interface *, const struct usb_device_id *);
975:	int usb_register_device_driver(struct usb_device_driver *, struct module *);
1043:	int usb_register_driver(struct usb_driver *, struct module *, const char *);
114:	ssize_t usb_show_dynids(struct usb_dynids *, char *);
42:	ssize_t usb_store_new_id(struct usb_dynids *, const struct usb_device_id *, struct device_driver *, const char *, size_t);
1200:	void usb_unbind_and_rebind_marked_interfaces(struct usb_device *);
943:	static int __usb_bus_reprobe_drivers(struct device *, void *);
131:	static ssize_t new_id_show(struct device_driver *, char *);
138:	static ssize_t new_id_store(struct device_driver *, const char *, size_t);
178:	static ssize_t remove_id_show(struct device_driver *, char *);
150:	static ssize_t remove_id_store(struct device_driver *, const char *, size_t);
855:	static int usb_device_match(struct device *, struct device_driver *);
249:	static int usb_probe_device(struct device *);
318:	static int usb_probe_interface(struct device *);
902:	static int usb_uevent(struct device *, struct kobj_uevent_env *);
303:	static int usb_unbind_device(struct device *);
428:	static int usb_unbind_interface(struct device *);

File drivers/usb/core/endpoint.c:
149:	int usb_create_ep_devs(struct device *, struct usb_host_endpoint *, struct usb_device *);
183:	void usb_remove_ep_devs(struct usb_host_endpoint *);
47:	static ssize_t bEndpointAddress_show(struct device *, struct device_attribute *, char *);
49:	static ssize_t bInterval_show(struct device *, struct device_attribute *, char *);
46:	static ssize_t bLength_show(struct device *, struct device_attribute *, char *);
48:	static ssize_t bmAttributes_show(struct device *, struct device_attribute *, char *);
102:	static ssize_t direction_show(struct device *, struct device_attribute *, char *);
137:	static void ep_device_release(struct device *);
83:	static ssize_t interval_show(struct device *, struct device_attribute *, char *);
59:	static ssize_t type_show(struct device *, struct device_attribute *, char *);
51:	static ssize_t wMaxPacketSize_show(struct device *, struct device_attribute *, char *);

File drivers/usb/core/file.c:
230:	void usb_deregister_dev(struct usb_interface *, struct usb_class_driver *);
132:	void usb_major_cleanup(void);
120:	int usb_major_init(void);
156:	int usb_register_dev(struct usb_interface *, struct usb_class_driver *);
65:	static char *usb_devnode(const struct device *, umode_t *);
34:	static int usb_open(struct inode *, struct file *);

File drivers/usb/core/generic.c:
56:	int usb_choose_configuration(struct usb_device *);
253:	void usb_generic_driver_disconnect(struct usb_device *);
226:	int usb_generic_driver_probe(struct usb_device *);
198:	static int __check_for_non_generic_match(struct device_driver *, void *);
211:	static bool usb_generic_driver_match(struct usb_device *);

File drivers/usb/core/hcd.c:
2567:	struct usb_hcd *__usb_create_hcd(const struct hc_driver *, struct device *, struct device *, const char *, struct usb_hcd *);
2811:	int usb_add_hcd(struct usb_hcd *, unsigned int, unsigned long);
2036:	int usb_alloc_streams(struct usb_interface *, struct usb_host_endpoint **, unsigned int, unsigned int, gfp_t);
1094:	long usb_calc_bus_time(int, int, int, int);
2668:	struct usb_hcd *usb_create_hcd(const struct hc_driver *, struct device *, const char *);
2645:	struct usb_hcd *usb_create_shared_hcd(const struct hc_driver *, struct device *, const char *, struct usb_hcd *);
2086:	int usb_free_streams(struct usb_interface *, struct usb_host_endpoint **, unsigned int, gfp_t);
2702:	struct usb_hcd *usb_get_hcd(struct usb_hcd *);
2515:	void usb_hc_died(struct usb_hcd *);
1862:	int usb_hcd_alloc_bandwidth(struct usb_device *, struct usb_host_config *, struct usb_host_interface *, struct usb_host_interface *);
1211:	int usb_hcd_check_unlink_urb(struct usb_hcd *, struct urb *, int);
1984:	void usb_hcd_disable_endpoint(struct usb_device *, struct usb_host_endpoint *);
1068:	void usb_hcd_end_port_resume(struct usb_bus *, int);
2725:	int usb_hcd_find_raw_port_number(struct usb_hcd *, int);
1783:	void usb_hcd_flush_endpoint(struct usb_device *, struct usb_host_endpoint *);
2129:	int usb_hcd_get_frame_number(struct usb_device *);
1744:	void usb_hcd_giveback_urb(struct usb_hcd *, struct urb *, int);
2474:	irqreturn_t usb_hcd_irq(int, void *);
2717:	int usb_hcd_is_primary_hcd(struct usb_hcd *);
1153:	int usb_hcd_link_urb_to_ep(struct usb_hcd *, struct urb *);
1407:	int usb_hcd_map_urb_for_dma(struct usb_hcd *, struct urb *, gfp_t);
3100:	void usb_hcd_platform_shutdown(struct platform_device *);
752:	void usb_hcd_poll_rh_status(struct usb_hcd *);
2003:	void usb_hcd_reset_endpoint(struct usb_device *, struct usb_host_endpoint *);
3112:	int usb_hcd_setup_local_mem(struct usb_hcd *, phys_addr_t, dma_addr_t, size_t);
1046:	void usb_hcd_start_port_resume(struct usb_bus *, int);
1529:	int usb_hcd_submit_urb(struct urb *, gfp_t);
2120:	void usb_hcd_synchronize_unlinks(struct usb_device *);
1611:	int usb_hcd_unlink_urb(struct urb *, int);
1244:	void usb_hcd_unlink_urb_from_ep(struct usb_hcd *, struct urb *);
1360:	void usb_hcd_unmap_urb_for_dma(struct usb_hcd *, struct urb *);
1332:	void usb_hcd_unmap_urb_setup_for_dma(struct usb_hcd *, struct urb *);
2710:	void usb_put_hcd(struct usb_hcd *);
3032:	void usb_remove_hcd(struct usb_hcd *);
1644:	static void __usb_hcd_giveback_urb(struct urb *);
2493:	static void hcd_died_work(struct work_struct *);
982:	static int register_root_hub(struct usb_hcd *);
803:	static void rh_timer_func(struct timer_list *);
1589:	static int unlink1(struct usb_hcd *, struct urb *, int);
1688:	static void usb_giveback_urb_bh(struct tasklet_struct *);
2733:	static int usb_hcd_request_irqs(struct usb_hcd *, unsigned int, unsigned long);
2787:	static void usb_stop_hcd(struct usb_hcd *);

File drivers/usb/core/hub.c:
4582:	int hub_port_debounce(struct usb_hub *, int, bool);
2644:	int usb_authorize_device(struct usb_device *);
431:	int usb_clear_port_feature(struct usb_device *, int, int);
2629:	int usb_deauthorize_device(struct usb_device *);
2011:	bool usb_device_is_owned(struct usb_device *);
148:	int usb_device_supports_lpm(struct usb_device *);
4485:	int usb_disable_lpm(struct usb_device *);
4503:	int usb_disable_ltm(struct usb_device *);
2208:	void usb_disconnect(struct usb_device **);
4491:	void usb_enable_lpm(struct usb_device *);
4509:	void usb_enable_ltm(struct usb_device *);
4625:	void usb_ep0_reinit(struct usb_device *);
6285:	void usb_hub_adjust_deviceremovable(struct usb_device *, struct usb_hub_descriptor *);
1966:	int usb_hub_claim_port(struct usb_device *, unsigned int, struct usb_dev_state *);
5918:	void usb_hub_cleanup(void);
869:	int usb_hub_clear_tt_buffer(struct urb *);
6274:	struct usb_device *usb_hub_find_child(struct usb_device *, int);
5893:	int usb_hub_init(void);
620:	int usb_hub_port_status(struct usb_hub *, int, u16 *, u16 *);
1998:	void usb_hub_release_all_ports(struct usb_device *, struct usb_dev_state *);
1982:	int usb_hub_release_port(struct usb_device *, unsigned int, struct usb_dev_state *);
835:	int usb_hub_set_port_power(struct usb_device *, struct usb_hub *, int, bool);
141:	struct usb_hub *usb_hub_to_struct_hub(struct usb_device *);
684:	void usb_kick_hub_wq(struct usb_device *);
2523:	int usb_new_device(struct usb_device *);
4560:	int usb_port_disable(struct usb_device *);
3130:	int usb_port_is_power_on(struct usb_hub *, unsigned int);
6254:	void usb_queue_reset_device(struct usb_interface *);
999:	int usb_remove_device(struct usb_device *);
6131:	int usb_reset_device(struct usb_device *);
2056:	void usb_set_device_state(struct usb_device *, enum usb_device_state);
4494:	int usb_unlocked_disable_lpm(struct usb_device *);
4500:	void usb_unlocked_enable_lpm(struct usb_device *);
700:	void usb_wakeup_notification(struct usb_device *, unsigned int);
5146:	static int descriptors_changed(struct usb_device *, struct usb_device_descriptor *, struct usb_host_bos *);
2701:	static enum usb_ssp_rate get_port_ssp_rate(struct usb_device *, u32);
1028:	static void hub_activate(struct usb_hub *, enum hub_activation_type);
1715:	static void hub_disconnect(struct usb_interface *);
5715:	static void hub_event(struct work_struct *);
591:	static int hub_ext_port_status(struct usb_hub *, int, int, u16 *, u16 *, u32 *);
936:	static int hub_hub_status(struct usb_hub *, u16 *, u16 *);
1301:	static void hub_init_func2(struct work_struct *);
1308:	static void hub_init_func3(struct work_struct *);
1910:	static int hub_ioctl(struct usb_interface *, unsigned int, void *);
722:	static void hub_irq(struct urb *);
4530:	static int hub_port_disable(struct usb_hub *, int, int);
4718:	static int hub_port_init(struct usb_hub *, struct usb_device *, int, int);
2946:	static int hub_port_reset(struct usb_hub *, int, struct usb_device *, unsigned int, bool);
1367:	static int hub_post_reset(struct usb_interface *);
5099:	static unsigned int hub_power_remaining(struct usb_hub *);
1356:	static int hub_pre_reset(struct usb_interface *);
1783:	static int hub_probe(struct usb_interface *, const struct usb_device_id *);
1319:	static void hub_quiesce(struct usb_hub *, enum hub_quiescing_type);
627:	static void hub_resubmit_irq_urb(struct usb_hub *);
649:	static void hub_retry_irq_urb(struct timer_list *);
786:	static void hub_tt_work(struct work_struct *);
657:	static void kick_hub_wq(struct usb_hub *);
481:	static void led_work(struct work_struct *);
2021:	static void recursively_mark_NOTATTACHED(struct usb_device *);
318:	static void usb_set_lpm_parameters(struct usb_device *);

File drivers/usb/core/message.c:
2285:	int cdc_parse_cdc_header(struct usb_cdc_parsed_header *, struct usb_interface *, u8 *, int);
1811:	void usb_authorize_interface(struct usb_interface *);
363:	int usb_bulk_msg(struct usb_device *, unsigned int, void *, int, int *, int);
1018:	char *usb_cache_string(struct usb_device *, int);
1209:	int usb_clear_halt(struct usb_device *, int);
136:	int usb_control_msg(struct usb_device *, unsigned int, __u8, __u8, __u16, __u16, void *, __u16, int);
263:	int usb_control_msg_recv(struct usb_device *, __u8, __u8, __u8, __u16, __u16, void *, __u16, int, gfp_t);
198:	int usb_control_msg_send(struct usb_device *, __u8, __u8, __u8, __u16, __u16, const void *, __u16, int, gfp_t);
1789:	void usb_deauthorize_interface(struct usb_interface *);
1394:	void usb_disable_device(struct usb_device *, int);
1284:	void usb_disable_endpoint(struct usb_device *, unsigned int, bool);
1343:	void usb_disable_interface(struct usb_device *, struct usb_interface *, bool);
2249:	int usb_driver_set_configuration(struct usb_device *, int);
1455:	void usb_enable_endpoint(struct usb_device *, struct usb_host_endpoint *, bool);
1479:	void usb_enable_interface(struct usb_device *, struct usb_interface *, bool);
780:	int usb_get_descriptor(struct usb_device *, unsigned char, unsigned char, void *, int);
1061:	int usb_get_device_descriptor(struct usb_device *, unsigned int);
1128:	int usb_get_status(struct usb_device *, int, int, int, void *);
324:	int usb_interrupt_msg(struct usb_device *, unsigned int, void *, int, int *, int);
1693:	int usb_reset_configuration(struct usb_device *);
1319:	void usb_reset_endpoint(struct usb_device *, unsigned int);
1958:	int usb_set_configuration(struct usb_device *, int);
1528:	int usb_set_interface(struct usb_device *, int, int);
1086:	int usb_set_isoch_delay(struct usb_device *);
720:	void usb_sg_cancel(struct usb_sg_request *);
501:	int usb_sg_init(struct usb_sg_request *, struct usb_device *, unsigned int, unsigned int, struct scatterlist *, int, size_t, gfp_t);
650:	void usb_sg_wait(struct usb_sg_request *);
967:	int usb_string(struct usb_device *, int, char *, size_t);
1896:	static void __usb_queue_reset_device(struct work_struct *);
2196:	static void driver_set_config_work(struct work_struct *);
404:	static void sg_complete(struct urb *);
34:	static void usb_api_blocking_completion(struct urb *);
1361:	static void usb_disable_device_endpoints(struct usb_device *, int);
832:	static int usb_get_string(struct usb_device *, unsigned short, unsigned char, void *, int);
1822:	static int usb_if_uevent(struct device *, struct kobj_uevent_env *);
1772:	static void usb_release_interface(struct device *);
49:	static int usb_start_wait_urb(struct urb *, int, int *);
872:	static int usb_string_sub(struct usb_device *, unsigned int, unsigned int, unsigned char *);

File drivers/usb/core/notify.c:
60:	void usb_notify_add_bus(struct usb_bus *);
49:	void usb_notify_add_device(struct usb_device *);
65:	void usb_notify_remove_bus(struct usb_bus *);
54:	void usb_notify_remove_device(struct usb_device *);
29:	void usb_register_notify(struct notifier_block *);
42:	void usb_unregister_notify(struct notifier_block *);

File drivers/usb/core/of.c:
25:	struct device_node *usb_of_get_device_node(struct usb_device *, int);
92:	struct device_node *usb_of_get_interface_node(struct usb_device *, u8, u8);
57:	bool usb_of_has_combined_node(struct usb_device *);

File drivers/usb/core/phy.c:
49:	struct usb_phy_roothub *usb_phy_roothub_alloc(struct device *);
154:	int usb_phy_roothub_calibrate(struct usb_phy_roothub *);
105:	int usb_phy_roothub_exit(struct usb_phy_roothub *);
78:	int usb_phy_roothub_init(struct usb_phy_roothub *);
202:	void usb_phy_roothub_power_off(struct usb_phy_roothub *);
175:	int usb_phy_roothub_power_on(struct usb_phy_roothub *);
227:	int usb_phy_roothub_resume(struct device *, struct usb_phy_roothub *);
126:	int usb_phy_roothub_set_mode(struct usb_phy_roothub *, enum phy_mode);
214:	int usb_phy_roothub_suspend(struct device *, struct usb_phy_roothub *);

File drivers/usb/core/port.c:
669:	int usb_hub_create_port_device(struct usb_hub *, int);
759:	void usb_hub_remove_port_device(struct usb_hub *, int);
138:	static ssize_t connect_type_show(struct device *, struct device_attribute *, char *);
643:	static int connector_bind(struct device *, struct device *, void *);
658:	static void connector_unbind(struct device *, struct device *, void *);
47:	static ssize_t disable_show(struct device *, struct device_attribute *, char *);
82:	static ssize_t disable_store(struct device *, struct device_attribute *, const char *, size_t);
21:	static ssize_t early_stop_show(struct device *, struct device_attribute *, char *);
29:	static ssize_t early_stop_store(struct device *, struct device_attribute *, const char *, size_t);
502:	static void link_peers_report(struct usb_port *, struct usb_port *);
129:	static ssize_t location_show(struct device *, struct device_attribute *, char *);
557:	static int match_location(struct usb_device *, void *);
163:	static ssize_t over_current_count_show(struct device *, struct device_attribute *, char *);
172:	static ssize_t quirks_show(struct device *, struct device_attribute *, char *);
180:	static ssize_t quirks_store(struct device *, struct device_attribute *, const char *, size_t);
194:	static ssize_t usb3_lpm_permit_show(struct device *, struct device_attribute *, char *);
215:	static ssize_t usb3_lpm_permit_store(struct device *, struct device_attribute *, const char *, size_t);
294:	static void usb_port_device_release(struct device *);
406:	static void usb_port_shutdown(struct device *);

File drivers/usb/core/quirks.c:
709:	void usb_detect_interface_quirks(struct usb_device *);
681:	void usb_detect_quirks(struct usb_device *);
579:	bool usb_endpoint_is_ignored(struct usb_device *, struct usb_host_interface *, struct usb_endpoint_descriptor *);
722:	void usb_release_quirk_list(void);
28:	static int quirks_param_set(const char *, const struct kernel_param *);
639:	static u32 usb_detect_static_quirks(struct usb_device *, const struct usb_device_id *);

File drivers/usb/core/sysfs.c:
1021:	int usb_create_sysfs_dev_files(struct usb_device *);
1241:	void usb_create_sysfs_intf_files(struct usb_interface *);
1050:	void usb_remove_sysfs_dev_files(struct usb_device *);
1258:	void usb_remove_sysfs_intf_files(struct usb_interface *);
914:	static ssize_t authorized_default_show(struct device *, struct device_attribute *, char *);
925:	static ssize_t authorized_default_store(struct device *, struct device_attribute *, const char *, size_t);
727:	static ssize_t authorized_show(struct device *, struct device_attribute *, char *);
739:	static ssize_t authorized_store(struct device *, struct device_attribute *, const char *, size_t);
265:	static ssize_t avoid_reset_quirk_show(struct device *, struct device_attribute *, char *);
274:	static ssize_t avoid_reset_quirk_store(struct device *, struct device_attribute *, const char *, size_t);
1095:	static ssize_t bAlternateSetting_show(struct device *, struct device_attribute *, char *);
91:	static ssize_t bConfigurationValue_show(struct device *, struct device_attribute *, char *);
93:	static ssize_t bConfigurationValue_store(struct device *, struct device_attribute *, const char *, size_t);
719:	static ssize_t bDeviceClass_show(struct device *, struct device_attribute *, char *);
721:	static ssize_t bDeviceProtocol_show(struct device *, struct device_attribute *, char *);
720:	static ssize_t bDeviceSubClass_show(struct device *, struct device_attribute *, char *);
1097:	static ssize_t bInterfaceClass_show(struct device *, struct device_attribute *, char *);
1094:	static ssize_t bInterfaceNumber_show(struct device *, struct device_attribute *, char *);
1099:	static ssize_t bInterfaceProtocol_show(struct device *, struct device_attribute *, char *);
1098:	static ssize_t bInterfaceSubClass_show(struct device *, struct device_attribute *, char *);
723:	static ssize_t bMaxPacketSize0_show(struct device *, struct device_attribute *, char *);
52:	static ssize_t bMaxPower_show(struct device *, struct device_attribute *, char *);
722:	static ssize_t bNumConfigurations_show(struct device *, struct device_attribute *, char *);
1096:	static ssize_t bNumEndpoints_show(struct device *, struct device_attribute *, char *);
49:	static ssize_t bNumInterfaces_show(struct device *, struct device_attribute *, char *);
705:	static ssize_t bcdDevice_show(struct device *, struct device_attribute *, char *);
50:	static ssize_t bmAttributes_show(struct device *, struct device_attribute *, char *);
203:	static ssize_t busnum_show(struct device *, struct device_attribute *, char *);
71:	static ssize_t configuration_show(struct device *, struct device_attribute *, char *);
829:	static umode_t dev_string_attrs_are_visible(struct kobject *, struct attribute *, int);
213:	static ssize_t devnum_show(struct device *, struct device_attribute *, char *);
223:	static ssize_t devpath_show(struct device *, struct device_attribute *, char *);
113:	static ssize_t devspec_show(struct device *, struct device_attribute *, char *);
1075:	static ssize_t iad_bFirstInterface_show(struct device *, struct device_attribute *, char *);
1077:	static ssize_t iad_bFunctionClass_show(struct device *, struct device_attribute *, char *);
1079:	static ssize_t iad_bFunctionProtocol_show(struct device *, struct device_attribute *, char *);
1078:	static ssize_t iad_bFunctionSubClass_show(struct device *, struct device_attribute *, char *);
1076:	static ssize_t iad_bInterfaceCount_show(struct device *, struct device_attribute *, char *);
704:	static ssize_t idProduct_show(struct device *, struct device_attribute *, char *);
703:	static ssize_t idVendor_show(struct device *, struct device_attribute *, char *);
955:	static ssize_t interface_authorized_default_show(struct device *, struct device_attribute *, char *);
971:	static ssize_t interface_authorized_default_store(struct device *, struct device_attribute *, const char *, size_t);
1163:	static ssize_t interface_authorized_show(struct device *, struct device_attribute *, char *);
1174:	static ssize_t interface_authorized_store(struct device *, struct device_attribute *, const char *, size_t);
1101:	static ssize_t interface_show(struct device *, struct device_attribute *, char *);
1219:	static umode_t intf_assoc_attrs_are_visible(struct kobject *, struct attribute *, int);
305:	static ssize_t ltm_capable_show(struct device *, struct device_attribute *, char *);
142:	static ssize_t manufacturer_show(struct device *, struct device_attribute *, char *);
245:	static ssize_t maxchild_show(struct device *, struct device_attribute *, char *);
1115:	static ssize_t modalias_show(struct device *, struct device_attribute *, char *);
141:	static ssize_t product_show(struct device *, struct device_attribute *, char *);
255:	static ssize_t quirks_show(struct device *, struct device_attribute *, char *);
862:	static ssize_t read_descriptors(struct file *, struct kobject *, struct bin_attribute *, char *, loff_t, size_t);
759:	static ssize_t remove_store(struct device *, struct device_attribute *, const char *, size_t);
183:	static ssize_t rx_lanes_show(struct device *, struct device_attribute *, char *);
143:	static ssize_t serial_show(struct device *, struct device_attribute *, char *);
145:	static ssize_t speed_show(struct device *, struct device_attribute *, char *);
1142:	static ssize_t supports_autosuspend_show(struct device *, struct device_attribute *, char *);
193:	static ssize_t tx_lanes_show(struct device *, struct device_attribute *, char *);
295:	static ssize_t urbnum_show(struct device *, struct device_attribute *, char *);
233:	static ssize_t version_show(struct device *, struct device_attribute *, char *);

File drivers/usb/core/urb.c:
71:	struct urb *usb_alloc_urb(int, gfp_t);
1048:	int usb_anchor_empty(struct usb_anchor *);
953:	void usb_anchor_resume_wakeups(struct usb_anchor *);
939:	void usb_anchor_suspend_wakeups(struct usb_anchor *);
127:	void usb_anchor_urb(struct urb *, struct usb_anchor *);
803:	void usb_block_urb(struct urb *);
94:	void usb_free_urb(struct urb *);
993:	struct urb *usb_get_from_anchor(struct usb_anchor *);
111:	struct urb *usb_get_urb(struct urb *);
44:	void usb_init_urb(struct urb *);
823:	void usb_kill_anchored_urbs(struct usb_anchor *);
714:	void usb_kill_urb(struct urb *);
204:	int usb_pipe_type_check(struct usb_device *, unsigned int);
861:	void usb_poison_anchored_urbs(struct usb_anchor *);
761:	void usb_poison_urb(struct urb *);
1020:	void usb_scuttle_anchored_urbs(struct usb_anchor *);
368:	int usb_submit_urb(struct urb *, gfp_t);
165:	void usb_unanchor_urb(struct urb *);
920:	void usb_unlink_anchored_urbs(struct usb_anchor *);
675:	int usb_unlink_urb(struct urb *);
895:	void usb_unpoison_anchored_urbs(struct usb_anchor *);
782:	void usb_unpoison_urb(struct urb *);
225:	int usb_urb_ep_type_check(const struct urb *);
974:	int usb_wait_anchor_empty_timeout(struct usb_anchor *, unsigned int);
150:	static void __usb_unanchor_urb(struct urb *, struct usb_anchor *);

File drivers/usb/core/usb.c:
880:	int __usb_get_extra_descriptor(char *, unsigned int, unsigned char, void **, size_t);
932:	void *usb_alloc_coherent(struct usb_device *, size_t, gfp_t, dma_addr_t *);
574:	struct usb_device *usb_alloc_dev(struct usb_device *, struct usb_bus *, unsigned int);
307:	struct usb_host_interface *usb_altnum_to_altsetting(const struct usb_interface *, unsigned int);
58:	int usb_disabled(void);
220:	struct usb_host_interface *usb_find_alt_setting(struct usb_host_config *, unsigned int, unsigned int);
134:	int usb_find_common_endpoints(struct usb_host_interface *, struct usb_endpoint_descriptor **, struct usb_endpoint_descriptor **, struct usb_endpoint_descriptor **, struct usb_endpoint_descriptor **);
180:	int usb_find_common_endpoints_reverse(struct usb_host_interface *, struct usb_endpoint_descriptor **, struct usb_endpoint_descriptor **, struct usb_endpoint_descriptor **, struct usb_endpoint_descriptor **);
351:	struct usb_interface *usb_find_interface(struct usb_driver *, int);
393:	int usb_for_each_dev(void *, int (*)(struct usb_device *, void *));
952:	void usb_free_coherent(struct usb_device *, size_t, void *, dma_addr_t);
868:	int usb_get_current_frame_number(struct usb_device *);
698:	struct usb_device *usb_get_dev(struct usb_device *);
736:	struct usb_interface *usb_get_intf(struct usb_interface *);
271:	struct usb_interface *usb_ifnum_to_if(const struct usb_device *, unsigned int);
773:	struct device *usb_intf_get_dma_device(struct usb_interface *);
821:	int usb_lock_device_for_reset(struct usb_device *, const struct usb_interface *);
713:	void usb_put_dev(struct usb_device *);
752:	void usb_put_intf(struct usb_interface *);
373:	static int __each_dev(struct device *, void *);
326:	static int __find_interface(struct device *, const void *);
966:	static int usb_bus_notify(struct notifier_block *, unsigned long, void *);
426:	static int usb_dev_uevent(struct device *, struct kobj_uevent_env *);
508:	static char *usb_devnode(struct device *, umode_t *, kuid_t *, kgid_t *);
1062:	static void usb_exit(void);
1007:	static int usb_init(void);
408:	static void usb_release_dev(struct device *);

File drivers/usb/host/xhci-dbg.c:
22:	void xhci_dbg_trace(struct xhci_hcd *, void (*)(struct va_format *), const char *, ...);
13:	char *xhci_get_slot_state(struct xhci_hcd *, struct xhci_container_ctx *);

File drivers/usb/host/xhci-debugfs.h:
126:	static void xhci_debugfs_remove_root(void);

File drivers/usb/host/xhci-ext-caps.c:
84:	int xhci_ext_cap_init(struct xhci_hcd *);
23:	static void xhci_intel_unregister_pdev(void *);

File drivers/usb/host/xhci-hub.c:
460:	int xhci_find_slot_id_by_port(struct usb_hcd *, struct xhci_hcd *, u16);
655:	struct xhci_hub *xhci_get_rhub(struct usb_hcd *);
1196:	int xhci_hub_control(struct usb_hcd *, u16, u16, u16, char *, u16);
1635:	int xhci_hub_status_data(struct usb_hcd *, char *);
444:	u32 xhci_port_state_to_neutral(u32);
562:	void xhci_ring_device(struct xhci_hcd *, int);
783:	void xhci_set_link_state(struct xhci_hcd *, struct xhci_port *, u32);
827:	void xhci_test_and_clear_bit(struct xhci_hcd *, struct xhci_port *, u32);
720:	static int xhci_enter_test_mode(struct xhci_hcd *, u16, u16, unsigned long *);
764:	static int xhci_exit_test_mode(struct xhci_hcd *);
669:	static void xhci_set_port_power(struct xhci_hcd *, struct usb_hcd *, u16, bool, unsigned long *);
800:	static void xhci_set_remote_wake_mask(struct xhci_hcd *, struct xhci_port *, u16);
489:	static int xhci_stop_device(struct xhci_hcd *, int, int);

File drivers/usb/host/xhci-mem.c:
1733:	struct xhci_command *xhci_alloc_command(struct xhci_hcd *, bool, gfp_t);
1759:	struct xhci_command *xhci_alloc_command_with_ctx(struct xhci_hcd *, bool, gfp_t);
468:	struct xhci_container_ctx *xhci_alloc_container_ctx(struct xhci_hcd *, int, gfp_t);
1792:	int xhci_alloc_erst(struct xhci_hcd *, struct xhci_ring *, struct xhci_erst *, gfp_t);
603:	struct xhci_stream_info *xhci_alloc_stream_info(struct xhci_hcd *, unsigned int, unsigned int, unsigned int, gfp_t);
820:	int xhci_alloc_tt_info(struct xhci_hcd *, struct xhci_virt_device *, struct usb_device *, struct usb_tt *, gfp_t);
964:	int xhci_alloc_virt_device(struct xhci_hcd *, int, struct usb_device *, gfp_t);
1534:	void xhci_clear_endpoint_bw_info(struct xhci_bw_info *);
1037:	void xhci_copy_ep0_dequeue_into_input_ctx(struct xhci_hcd *, struct usb_device *);
584:	struct xhci_ring *xhci_dma_to_transfer_ring(struct xhci_virt_ep *, u64);
1602:	void xhci_endpoint_copy(struct xhci_hcd *, struct xhci_container_ctx *, struct xhci_container_ctx *, unsigned int);
1416:	int xhci_endpoint_init(struct xhci_hcd *, struct xhci_virt_device *, struct usb_device *, struct usb_host_endpoint *, gfp_t);
1515:	void xhci_endpoint_zero(struct xhci_hcd *, struct xhci_virt_device *, struct usb_host_endpoint *);
1783:	void xhci_free_command(struct xhci_hcd *, struct xhci_command *);
494:	void xhci_free_container_ctx(struct xhci_hcd *, struct xhci_container_ctx *);
411:	void xhci_free_endpoint_ring(struct xhci_hcd *, struct xhci_virt_device *, unsigned int);
1822:	void xhci_free_erst(struct xhci_hcd *, struct xhci_erst *);
758:	void xhci_free_stream_info(struct xhci_hcd *, struct xhci_stream_info *);
865:	void xhci_free_virt_device(struct xhci_hcd *, int);
522:	struct xhci_ep_ctx *xhci_get_ep_ctx(struct xhci_hcd *, struct xhci_container_ctx *, unsigned int);
503:	struct xhci_input_control_ctx *xhci_get_input_control_ctx(struct xhci_container_ctx *);
512:	struct xhci_slot_ctx *xhci_get_slot_ctx(struct xhci_hcd *, struct xhci_container_ctx *);
296:	void xhci_initialize_ring_info(struct xhci_ring *, unsigned int);
1835:	void xhci_mem_cleanup(struct xhci_hcd *);
2378:	int xhci_mem_init(struct xhci_hcd *, gfp_t);
371:	struct xhci_ring *xhci_ring_alloc(struct xhci_hcd *, unsigned int, unsigned int, enum xhci_ring_type, unsigned int, gfp_t);
423:	int xhci_ring_expansion(struct xhci_hcd *, struct xhci_ring *, unsigned int, gfp_t);
280:	void xhci_ring_free(struct xhci_hcd *, struct xhci_ring *);
1088:	int xhci_setup_addressable_virt_dev(struct xhci_hcd *, struct usb_device *);
745:	void xhci_setup_no_streams_ep_input_ctx(struct xhci_ep_ctx *, struct xhci_virt_ep *);
721:	void xhci_setup_streams_ep_input_ctx(struct xhci_hcd *, struct xhci_ep_ctx *, struct xhci_stream_info *);
1628:	void xhci_slot_copy(struct xhci_hcd *, struct xhci_container_ctx *, struct xhci_container_ctx *);
1544:	void xhci_update_bw_info(struct xhci_hcd *, struct xhci_container_ctx *, struct xhci_input_control_ctx *, struct xhci_virt_device *);
1778:	void xhci_urb_free_priv(struct urb_priv *);
1645:	static int scratchpad_alloc(struct xhci_hcd *, gfp_t);
321:	static int xhci_alloc_segments_for_ring(struct xhci_hcd *, struct xhci_segment **, struct xhci_segment **, unsigned int, unsigned int, enum xhci_ring_type, unsigned int, gfp_t);
928:	static void xhci_free_virt_devices_depth_first(struct xhci_hcd *, int);
28:	static struct xhci_segment *xhci_segment_alloc(struct xhci_hcd *, unsigned int, unsigned int, gfp_t);
2090:	static void xhci_set_hc_event_deq(struct xhci_hcd *);
2272:	static int xhci_setup_port_arrays(struct xhci_hcd *, gfp_t);
1932:	static int xhci_test_trb_in_td(struct xhci_hcd *, struct xhci_segment *, union xhci_trb *, union xhci_trb *, dma_addr_t, struct xhci_segment *, char *, int);
219:	static int xhci_update_stream_segment_mapping(struct xarray *, struct xhci_ring *, struct xhci_segment *, struct xhci_segment *, gfp_t);

File drivers/usb/host/xhci-mvebu.h:
22:	static int xhci_mvebu_a3700_init_quirk(struct usb_hcd *);
17:	static int xhci_mvebu_mbus_init_quirk(struct usb_hcd *);

File drivers/usb/host/xhci-plat.c:
536:	static void xhci_plat_exit(void);
529:	static int xhci_plat_init(void);
176:	static int xhci_plat_probe(struct platform_device *);
77:	static void xhci_plat_quirks(struct device *, struct xhci_hcd *);
390:	static int xhci_plat_remove(struct platform_device *);
90:	static int xhci_plat_setup(struct usb_hcd *);
102:	static int xhci_plat_start(struct usb_hcd *);

File drivers/usb/host/xhci-rcar.h:
24:	static int xhci_rcar_init_quirk(struct usb_hcd *);
29:	static int xhci_rcar_resume_quirk(struct usb_hcd *);
20:	static void xhci_rcar_start(struct usb_hcd *);

File drivers/usb/host/xhci-ring.c:
3281:	unsigned int count_trbs(u64, u64);
158:	void inc_deq(struct xhci_hcd *, struct xhci_ring *);
2020:	struct xhci_segment *trb_in_td(struct xhci_hcd *, struct xhci_segment *, union xhci_trb *, union xhci_trb *, dma_addr_t, bool);
1555:	void xhci_cleanup_command_queue(struct xhci_hcd *);
1563:	void xhci_handle_command_timeout(struct work_struct *);
1220:	void xhci_hc_died(struct xhci_hcd *);
3015:	irqreturn_t xhci_irq(struct usb_hcd *);
2124:	int xhci_is_vendor_info_code(struct xhci_hcd *, unsigned int);
3103:	irqreturn_t xhci_msi_irq(int, void *);
4305:	int xhci_queue_address_device(struct xhci_hcd *, struct xhci_command *, dma_addr_t, u32, enum xhci_setup_dev);
3519:	int xhci_queue_bulk_tx(struct xhci_hcd *, gfp_t, struct urb *, int, unsigned int);
4330:	int xhci_queue_configure_endpoint(struct xhci_hcd *, struct xhci_command *, dma_addr_t, u32, bool);
3680:	int xhci_queue_ctrl_tx(struct xhci_hcd *, gfp_t, struct urb *, int, unsigned int);
4341:	int xhci_queue_evaluate_context(struct xhci_hcd *, struct xhci_command *, dma_addr_t, u32, bool);
3391:	int xhci_queue_intr_tx(struct xhci_hcd *, gfp_t, struct urb *, int, unsigned int);
4170:	int xhci_queue_isoc_tx_prepare(struct xhci_hcd *, gfp_t, struct urb *, int, unsigned int);
4321:	int xhci_queue_reset_device(struct xhci_hcd *, struct xhci_command *, u32);
4366:	int xhci_queue_reset_ep(struct xhci_hcd *, struct xhci_command *, int, unsigned int, enum xhci_ep_reset_type);
4297:	int xhci_queue_slot_control(struct xhci_hcd *, struct xhci_command *, u32, u32);
4354:	int xhci_queue_stop_endpoint(struct xhci_hcd *, struct xhci_command *, int, unsigned int, int);
4314:	int xhci_queue_vendor_command(struct xhci_hcd *, struct xhci_command *, u32, u32, u32, u32);
301:	void xhci_ring_cmd_db(struct xhci_hcd *);
478:	void xhci_ring_doorbell_for_active_rings(struct xhci_hcd *, unsigned int, unsigned int);
426:	void xhci_ring_ep_doorbell(struct xhci_hcd *, unsigned int, unsigned int, unsigned int);
69:	dma_addr_t xhci_trb_virt_to_dma(struct xhci_segment *, union xhci_trb *);
529:	struct xhci_ring *xhci_triad_to_transfer_ring(struct xhci_hcd *, unsigned int, unsigned int, unsigned int);
2138:	static int finish_td(struct xhci_hcd *, struct xhci_virt_ep *, struct xhci_ring *, struct xhci_td *, u32);
1641:	static void handle_cmd_completion(struct xhci_hcd *, struct xhci_event_cmd *);
3140:	static int prepare_ring(struct xhci_hcd *, struct xhci_ring *, u32, unsigned int, gfp_t);
3232:	static int prepare_transfer(struct xhci_hcd *, struct xhci_virt_device *, unsigned int, unsigned int, unsigned int, struct urb *, unsigned int, gfp_t);
4255:	static int queue_command(struct xhci_hcd *, struct xhci_command *, u32, u32, u32, u32, bool);
3117:	static void queue_trb(struct xhci_hcd *, struct xhci_ring *, bool, u32, u32, u32, u32);
453:	static void ring_doorbell_for_active_rings(struct xhci_hcd *, unsigned int, unsigned int);
485:	static struct xhci_virt_ep *xhci_get_virt_ep(struct xhci_hcd *, unsigned int, unsigned int);
1467:	static void xhci_handle_cmd_config_ep(struct xhci_hcd *, int, u32);
1059:	static void xhci_handle_cmd_stop_ep(struct xhci_hcd *, int, union xhci_trb *, u32);
898:	static int xhci_handle_halted_endpoint(struct xhci_hcd *, struct xhci_virt_ep *, struct xhci_td *, enum xhci_ep_reset_type);
331:	static void xhci_handle_stopped_cmd_ring(struct xhci_hcd *, struct xhci_command *);
948:	static int xhci_invalidate_cancelled_tds(struct xhci_virt_ep *);
1145:	static void xhci_kill_ring_urbs(struct xhci_hcd *, struct xhci_ring *);
801:	static int xhci_td_cleanup(struct xhci_hcd *, struct xhci_td *, struct xhci_ring *, int);
767:	static void xhci_unmap_td_bounce_buffer(struct xhci_hcd *, struct xhci_ring *, struct xhci_td *);
2979:	static void xhci_update_erst_dequeue(struct xhci_hcd *, union xhci_trb *);

File drivers/usb/host/xhci-trace.h:
38:	static void trace_xhci_dbg_address(struct va_format *);
58:	static void trace_xhci_dbg_cancel_urb(struct va_format *);
43:	static void trace_xhci_dbg_context_change(struct va_format *);
63:	static void trace_xhci_dbg_init(struct va_format *);
48:	static void trace_xhci_dbg_quirks(struct va_format *);
53:	static void trace_xhci_dbg_reset_ep(struct va_format *);
68:	static void trace_xhci_dbg_ring_expansion(struct va_format *);

File drivers/usb/host/xhci.c:
2003:	int xhci_add_endpoint(struct usb_hcd *, struct usb_device *, struct usb_host_endpoint *);
4082:	int xhci_alloc_dev(struct usb_hcd *, struct usb_device *);
3039:	int xhci_check_bandwidth(struct usb_hcd *, struct usb_device *);
4011:	int xhci_disable_slot(struct xhci_hcd *, u32);
1920:	int xhci_drop_endpoint(struct usb_hcd *, struct usb_device *, struct usb_host_endpoint *);
4371:	int xhci_find_raw_port_number(struct usb_hcd *, int);
3770:	void xhci_free_device_endpoint_resources(struct xhci_hcd *, struct xhci_virt_device *, bool);
5295:	int xhci_gen_setup(struct usb_hcd *, xhci_get_quirks_t);
1477:	unsigned int xhci_get_endpoint_index(struct usb_endpoint_descriptor *);
110:	int xhci_halt(struct xhci_hcd *);
68:	int xhci_handshake(void *, u32, u32, u64);
5497:	void xhci_init_driver(struct hc_driver *, const struct xhci_driver_overrides *);
1514:	unsigned int xhci_last_valid_endpoint(u32);
86:	void xhci_quiesce(struct xhci_hcd *);
170:	int xhci_reset(struct xhci_hcd *, u64);
3138:	void xhci_reset_bandwidth(struct usb_hcd *, struct usb_device *);
662:	int xhci_run(struct usb_hcd *);
793:	void xhci_shutdown(struct usb_hcd *);
133:	int xhci_start(struct xhci_hcd *);
5135:	int xhci_update_hub_device(struct usb_hcd *, struct usb_device *, struct usb_tt *, gfp_t);
2806:	void xhci_update_tt_active_eps(struct xhci_hcd *, struct xhci_virt_device *, int);
2732:	static void xhci_add_ep_to_interval_table(struct xhci_hcd *, struct xhci_bw_info *, struct xhci_interval_bw_table *, struct usb_device *, struct xhci_virt_ep *, struct xhci_tt_bw_info *);
4355:	static int xhci_address_device(struct usb_hcd *, struct usb_device *);
3511:	static int xhci_alloc_streams(struct usb_hcd *, struct usb_device *, struct usb_host_endpoint **, unsigned int, unsigned int, gfp_t);
1569:	static int xhci_check_maxpacket(struct xhci_hcd *, unsigned int, unsigned int, struct urb *, gfp_t);
5409:	static void xhci_clear_tt_buffer_complete(struct usb_hcd *, struct usb_host_endpoint *);
2919:	static int xhci_configure_endpoint(struct xhci_hcd *, struct usb_device *, struct xhci_command *, bool, bool);
5123:	static int xhci_disable_usb3_lpm_timeout(struct usb_hcd *, struct usb_device *, enum usb3_link_state);
3810:	static int xhci_discover_or_reset_device(struct usb_hcd *, struct usb_device *);
2668:	static void xhci_drop_ep_from_interval_table(struct xhci_hcd *, struct xhci_bw_info *, struct xhci_interval_bw_table *, struct usb_device *, struct xhci_virt_ep *, struct xhci_tt_bw_info *);
4360:	static int xhci_enable_device(struct usb_hcd *, struct usb_device *);
5117:	static int xhci_enable_usb3_lpm_timeout(struct usb_hcd *, struct usb_device *, enum usb3_link_state);
3175:	static void xhci_endpoint_disable(struct usb_hcd *, struct usb_host_endpoint *);
3227:	static void xhci_endpoint_reset(struct usb_hcd *, struct usb_host_endpoint *);
3972:	static void xhci_free_dev(struct usb_hcd *, struct usb_device *);
2312:	static void xhci_free_host_resources(struct xhci_hcd *, struct xhci_input_control_ctx *);
3678:	static int xhci_free_streams(struct usb_hcd *, struct usb_device *, struct usb_host_endpoint **, unsigned int, gfp_t);
5237:	static int xhci_get_frame(struct usb_hcd *);
5562:	static void xhci_hcd_fini(void);
5529:	static int xhci_hcd_init(void);
5257:	static void xhci_hcd_init_usb3_data(struct xhci_hcd *, struct usb_hcd *);
1434:	static int xhci_map_urb_for_dma(struct usb_hcd *, struct urb *, gfp_t);
614:	static int xhci_run_finished(struct xhci_hcd *);
5106:	static int xhci_set_usb2_hardware_lpm(struct usb_hcd *, struct usb_device *, int);
4171:	static int xhci_setup_device(struct usb_hcd *, struct usb_device *, enum xhci_setup_dev);
732:	static void xhci_stop(struct usb_hcd *);
1451:	static void xhci_unmap_urb_for_dma(struct usb_hcd *, struct urb *);
5112:	static int xhci_update_device(struct usb_hcd *, struct usb_device *);
1786:	static int xhci_urb_dequeue(struct usb_hcd *, struct urb *, int);
1643:	static int xhci_urb_enqueue(struct usb_hcd *, struct urb *, gfp_t);

File drivers/usb/host/xhci.h:
1982:	static bool xhci_hcd_is_usb3(struct usb_hcd *);

File drivers/usb/phy/of.c:
28:	enum usb_phy_interface of_usb_get_phy_mode(struct device_node *);

File drivers/usb/phy/phy-generic.c:
135:	int usb_gen_phy_init(struct usb_phy *);
157:	void usb_gen_phy_shutdown(struct usb_phy *);
206:	int usb_phy_gen_create_phy(struct device *, struct usb_phy_generic *);
33:	struct platform_device *usb_phy_generic_register(void);
40:	void usb_phy_generic_unregister(struct platform_device *);
101:	static irqreturn_t nop_gpio_vbus_thread(int, void *);
192:	static int nop_set_host(struct usb_otg *, struct usb_bus *);
173:	static int nop_set_peripheral(struct usb_otg *, struct usb_gadget *);
46:	static int nop_set_suspend(struct usb_phy *, int);
364:	static void usb_phy_generic_exit(void);
358:	static int usb_phy_generic_init(void);
286:	static int usb_phy_generic_probe(struct platform_device *);
333:	static int usb_phy_generic_remove(struct platform_device *);

File drivers/usb/phy/phy-ulpi-viewport.c:
29:	static int ulpi_viewport_read(struct usb_phy *, u32);
47:	static int ulpi_viewport_write(struct usb_phy *, u32, u32);

File drivers/usb/phy/phy-ulpi.c:
282:	struct usb_phy *devm_otg_ulpi_create(struct device *, struct usb_phy_io_ops *, unsigned int);
259:	struct usb_phy *otg_ulpi_create(struct usb_phy_io_ops *, unsigned int);
168:	static int ulpi_init(struct usb_phy *);
199:	static int ulpi_set_host(struct usb_otg *, struct usb_bus *);
225:	static int ulpi_set_vbus(struct usb_otg *, bool);

File drivers/usb/phy/phy.c:
464:	struct usb_phy *devm_usb_get_phy(struct device *, enum usb_phy_type);
535:	struct usb_phy *devm_usb_get_phy_by_node(struct device *, struct device_node *, struct notifier_block *);
594:	struct usb_phy *devm_usb_get_phy_by_phandle(struct device *, const char *, u8);
627:	void devm_usb_put_phy(struct device *, struct usb_phy *);
664:	int usb_add_phy(struct usb_phy *, enum usb_phy_type);
715:	int usb_add_phy_dev(struct usb_phy *);
493:	struct usb_phy *usb_get_phy(enum usb_phy_type);
280:	void usb_phy_get_charger_current(struct usb_phy *, unsigned int *, unsigned int *);
231:	void usb_phy_set_charger_current(struct usb_phy *, unsigned int);
317:	void usb_phy_set_charger_state(struct usb_phy *, enum usb_charger_state);
766:	void usb_phy_set_event(struct usb_phy *, unsigned long);
644:	void usb_put_phy(struct usb_phy *);
748:	void usb_remove_phy(struct usb_phy *);
177:	static void __usb_phy_get_charger_type(struct usb_phy *);
349:	static int devm_usb_phy_match(struct device *, void *, void *);
333:	static void devm_usb_phy_release(struct device *, void *);
340:	static void devm_usb_phy_release2(struct device *, void *);
364:	static int usb_add_extcon(struct usb_phy *);
208:	static int usb_phy_get_charger_type(struct notifier_block *, unsigned long, void *);
123:	static void usb_phy_notify_charger_work(struct work_struct *);
148:	static int usb_phy_uevent(struct device *, struct kobj_uevent_env *);

File drivers/usb/roles/class.c:
149:	struct usb_role_switch *fwnode_usb_role_switch_get(struct fwnode_handle *);
220:	const char *usb_role_string(enum usb_role);
187:	struct usb_role_switch *usb_role_switch_find_by_fwnode(const struct fwnode_handle *);
126:	struct usb_role_switch *usb_role_switch_get(struct device *);
388:	void *usb_role_switch_get_drvdata(struct usb_role_switch *);
70:	enum usb_role usb_role_switch_get_role(struct usb_role_switch *);
170:	void usb_role_switch_put(struct usb_role_switch *);
318:	struct usb_role_switch *usb_role_switch_register(struct device *, const struct usb_role_switch_desc *);
378:	void usb_role_switch_set_drvdata(struct usb_role_switch *, void *);
42:	int usb_role_switch_set_role(struct usb_role_switch *, enum usb_role);
366:	void usb_role_switch_unregister(struct usb_role_switch *);
230:	static ssize_t role_show(struct device *, struct device_attribute *, char *);
238:	static ssize_t role_store(struct device *, struct device_attribute *, const char *, size_t);
203:	static umode_t usb_role_switch_is_visible(struct kobject *, struct attribute *, int);
90:	static void *usb_role_switch_match(const struct fwnode_handle *, const char *, void *);
289:	static void usb_role_switch_release(struct device *);
278:	static int usb_role_switch_uevent(struct device *, struct kobj_uevent_env *);
401:	static void usb_roles_exit(void);
394:	static int usb_roles_init(void);
