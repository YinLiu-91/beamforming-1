/************************************************************************
  File Name: channel7.c
  Author: Fang Yuan
  Mail: yfang@nju.edu.cn
  Created Time: Fri 15 Jul 2016 04:20:57 PM CST
 ***********************************************************************/

/*
             4
        3         5
             7
        2         6
             1

    ��Ͳ�ڰ뾶4.25cm��Բ���Ͼ��ȷֲ�������һ��(7��)��

    ������ FS=16000Hz
    ���� c=34000cm/s
    �������Ի�Ͳƽ��
    ������Ϊ���յ㣬Զ���ӳټ��㷽����
        d = r*cos(theta - alpha_i)

*/

#include <stdio.h>
#include <signal.h>
#include "beamer7.h"

int main(int argc, char *argv)
{
    signal(SIGINT, savefile);

    init_delays();
    beamerinit(argc);
    filter_init();

    for(;;) {
        update_signal();
        noise_gen();
        beamformer();
        beamformer_filter();
    }   
}
// main.c
