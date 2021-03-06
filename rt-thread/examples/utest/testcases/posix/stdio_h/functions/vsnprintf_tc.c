#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static char buf[64] = {0};
static void WriteFrmtd(char *format, ...)
{
   va_list args;

   va_start(args, format);
   vsnprintf(buf, 22, format, args);
   va_end(args);
}

static int vsnprintf_entry(void)
{
    char buf[64] = {0};
    char test_data[] = "vsnprintf test:2021-8";
    snprintf(buf, 22,"vsnprintf test:%s-%d-%c %.02f 0x%x","2021" ,8 ,'1' ,3.14 ,0xff);

    if(strcmp(buf, test_data))
    {
        return -1;
    }
    return 0;
}

#include <utest.h>
static void test_vsnprintf(void)
{
    uassert_int_equal(vsnprintf_entry(), 0);
}
static void testcase(void)
{
    UTEST_UNIT_RUN(test_vsnprintf);
}
UTEST_TC_EXPORT(testcase, "rtt_posix_testcase.stdio_h."__FILE__, RT_NULL, RT_NULL, 10);

