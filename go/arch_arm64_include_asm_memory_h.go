package linux

const threadSize = 1 << threadShift

/*
 * VMAP'd stacks are allocated at page granularity, so we must ensure that such
 * stacks are a multiple of page size.
 */

const threadShift = minThreadShift

func init() {
	if configVmapStack == 1 && minThreadShift < pageShift {
		threadShift = pageShift
	} else {
		threadShift = minThreadShift
	}
}

/*
 * Generic and tag-based KASAN require 1/8th and 1/16th of the kernel virtual
 * address space for the shadow region respectively. They can bloat the stack
 * significantly, so double the (minimum) stack size when they are in use.
 */
//  #if defined(CONFIG_KASAN_GENERIC) || defined(CONFIG_KASAN_SW_TAGS)
//  #define KASAN_SHADOW_OFFSET	_AC(CONFIG_KASAN_SHADOW_OFFSET, UL)
//  #define KASAN_SHADOW_END	((UL(1) << (64 - KASAN_SHADOW_SCALE_SHIFT)) \
// 					 + KASAN_SHADOW_OFFSET)
//  #define PAGE_END		(KASAN_SHADOW_END - (1UL << (vabits_actual - KASAN_SHADOW_SCALE_SHIFT)))
//  #define KASAN_THREAD_SHIFT	1
//  #else
//  #define KASAN_THREAD_SHIFT	0
//  #define PAGE_END		(_PAGE_END(VA_BITS_MIN))
//  #endif /* CONFIG_KASAN */

//  #define MIN_THREAD_SHIFT	(14 + KASAN_THREAD_SHIFT)
// const minThreadShift = 14 + kasanThreadShift
