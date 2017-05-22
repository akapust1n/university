#include <linux/module.h>
#include <linux/spinlock.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/sched.h>

static const int R_AMNT =  6;
static const int W_AMNT =  2;
static const int SHOTS  = 10;

static struct task_struct **r_threads;
static struct task_struct **w_threads;
static atomic_t shmem = ATOMIC_INIT(0);
static rwlock_t lck;

struct thread_param
{
	int id;
	int shots;
} *thr_para;

void reader_thread(void *data)
{
	int i;
	struct thread_param t_param = *((struct thread_param *)data);
	int id = t_param.id;
	int shots = t_param.shots;
	printk("Reader #%d started\n", id);
	for (i = 0; i < shots; i++)
	{
		read_lock(&lck);
		printk ("Reader #%d (step %d): %d\n", id, i, atomic_read(&shmem));
		read_unlock(&lck);
		msleep(200);
	}
	printk("Reader #%d finished\n", id);
}

void writer_thread(void *data)
{
	int i;
	struct thread_param t_param = *((struct thread_param *)data);
	int id = t_param.id;
	int shots = t_param.shots;
	printk("Writer #%d started\n", id);
	for (i = 0; i < shots; i++)
	{
		write_lock(&lck);
		atomic_inc(&shmem);
		printk ("Writer #%d (step %d): %d\n", id, i, atomic_read(&shmem));
		write_unlock(&lck);
		msleep(200);
	}
	printk("Writer #%d finished\n", id);	
}

void alloc_kthread_mem(int r_amnt, int w_amnt)
{
	r_threads = (struct task_struct **)kmalloc(sizeof (struct task_struct *) * r_amnt, GFP_KERNEL);
	w_threads = (struct task_struct **)kmalloc(sizeof (struct task_struct *) * w_amnt, GFP_KERNEL);
}

void create_all_kthreads(int r_amnt, int w_amnt)
{
	int i;
	int max = r_amnt > w_amnt ? r_amnt : w_amnt;
	thr_para = (struct thread_param *)kmalloc(sizeof (struct thread_param) * max, GFP_KERNEL);
	for (i = 0; i < max; ++i)
	{
		(thr_para+i)->id = i;
		(thr_para+i)->shots = SHOTS;
	}	
	for (i = 0; i < r_amnt; ++i)
		r_threads[i] = kthread_create((void*)reader_thread, (void *)(thr_para+i), "reader_%d", i);
	for (i = 0; i < w_amnt; ++i)
		w_threads[i] = kthread_create((void*)writer_thread, (void *)(thr_para+i), "writer_%d", i);
}

void run_all_threads(int r_amnt, int w_amnt)
{
	int i;
	int max = r_amnt > w_amnt ? r_amnt : w_amnt;
	for (i = 0; i < max; ++i)
	{
		if (i < r_amnt)
			wake_up_process(r_threads[i]);		
		if (i < w_amnt)
			wake_up_process(w_threads[i]);
	}
}

int init_m(void)
{
	rwlock_init(&lck);
	alloc_kthread_mem(R_AMNT, W_AMNT);
	create_all_kthreads(R_AMNT, W_AMNT);
	run_all_threads(R_AMNT, W_AMNT);
	printk("Module inserted\n");
	return 0;
}

void exit_m(void)
{
	kfree(thr_para);
	kfree(r_threads);
	kfree(w_threads);
	printk("Module removed\n");
	return 0;
}

MODULE_LICENSE("GPL");
module_init(init_m);
module_exit(exit_m);