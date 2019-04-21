#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <asm/uaccess.h>

#define MODULE_NAME "GPIO"
#define MAJOR_NUM 60
#define GPIO_NUM 8
// gpio-id->gpio-name
const int NAMES[GPIO_NUM] = {160, 161, 162, 163, 164, 165, 166, 57};

char userStr[1024];
static int states[GPIO_NUM] = {0}; // 存放每個接腳對應狀態

static ssize_t drv_read(struct file *filp, char *buf, size_t count, loff_t *ppos)
{
	int i = 0;
	char str[128];

	printk("%s: Enter Read function\n", MODULE_NAME);
	// print GPIO states
	strcpy(userStr, "GPIO states:\n");
	strcat(userStr, "id\t");
	for (i = 0; i < GPIO_NUM; ++i) {
		sprintf(str, "%d\t", i);
		strcat(userStr, str);
	}
	strcat(userStr, "\n");
	strcat(userStr, "name\t");
	for (i = 0; i < GPIO_NUM; ++i) {
		sprintf(str, "%d\t", NAMES[i]);
		strcat(userStr, str);
	}
	strcat(userStr, "\n");
	strcat(userStr, "state\t");
	for (i = 0; i < GPIO_NUM; ++i) {
		sprintf(str, "%d\t", states[i]);
		strcat(userStr, str);
	}
	strcat(userStr, "\n");
	// sent to user
	copy_to_user(buf, userStr, 1024);
	printk("%s", userStr);

	printk("%s: Leave Read function\n", MODULE_NAME);
	return count;
}

static void write_str(const char filePath[], const char str[])
{
	struct file *fp;

	// 開檔前要先將記憶體資料存起來當檔案處理完關檔案後要寫回記憶體
	mm_segment_t old_fs;  // 建立紀錄記憶體中資料的結構
	old_fs = get_fs();  // 取得記憶體中資料放
	set_fs(get_ds());  // 將記憶體寫檔區段清空讓之後寫檔使用
	fp = filp_open(filePath, O_WRONLY, 0);  // 開檔
	
	loff_t pos = 0; //從第幾個char開始寫
	vfs_write(fp, str, strlen(str), &pos);  //寫檔
	//vfs_read(<檔案結構指標>,<資料存放陣列>,<資料大小>, &pos);  // 讀檔

	filp_close(fp, NULL);  // 關檔
	set_fs(old_fs);  // 回存記憶體中資料區段
}

static void export(unsigned int id)
{
	char buf[64];

	sprintf(buf, "%d", names[id]);
	write_str("/sys/class/gpio/export", buf);
}

static void unexport(unsigned int id)
{
	char buf[64];

	sprintf(buf, "%d", names[id]);
	write_str("/sys/class/gpio/unexport", buf);
}

static void set_dir(unsigned int id, const char dir[])
{
	char buf[64];

	sprintf(buf, "/sys/class/gpio/gpio%d/direction", names[id]);
	write_str(buf, dir);
}

static void set_value(unsigned int id, int value)
{
	char buf[64];

	sprintf(buf, "/sys/class/gpio/gpio%d/value", names[id]);
	write_str(buf, (value + '0'));
}

static ssize_t drv_write(struct file *filp, const char *buf, size_t count, loff_t *ppos)
{
	/*
	 * 設定接腳格式說明
	 * <gpio-id> <value>  // gpio-id: 接腳代號, value: 0或1
	*/
	printk("%s: Enter Write function\n", MODULE_NAME);
	
	copy_from_user(userStr, buf, 1024);
	userStr[count - 1] = 0;

	printk("%s\n", userStr);
	// TODO: 設定GPIO接腳
	
	printk("%s: Leave Write function\n", MODULE_NAME);
	return count;
}

int drv_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
{
	printk("%s: Enter I/O Control function\n", MODULE_NAME);
	printk("%s: Leave I/O Control function\n", MODULE_NAME);
	return 0;
}

static int drv_open(struct inode *inode, struct file *filp)
{
	printk("%s: Enter Open function\n", MODULE_NAME);
	printk("%s: Leave Open function\n", MODULE_NAME);
	return 0;
}

static int drv_release(struct inode *inode, struct file *filp)
{
	printk("%s: Enter Release function\n", MODULE_NAME);
	printk("%s: Leave Release function\n", MODULE_NAME);
	return 0;
}

struct file_operations drv_fops =
{
	read: drv_read,
	write: drv_write,
	unlocked_ioctl:	drv_ioctl,
	open: drv_open,
	release: drv_release,
};

static int init(void)
{
	if(register_chrdev(MAJOR_NUM, MODULE_NAME, &drv_fops) < 0){
		printk("%s: Module can't get major %d\n", MODULE_NAME, MAJOR_NUM);
		return (-EBUSY);
	}

	// GPIO export ,set dir, and init value
	int i = 0;
	for (i = 0; i < GPIO_NUM; ++i) {
		export(i);
		set_dir(i, "out");
		set_value(i, 0);
	}

	printk("%s: Module started.\n", MODULE_NAME);
	return 0;
}

static void exit(void)
{
	unregister_chrdev(MAJOR_NUM, MODULE_NAME);

	// TODO: GPIO unexport

	printk("%s: Module removed\n", MODULE_NAME);
}

module_init(init);
module_exit(exit);


