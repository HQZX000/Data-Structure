/*==============
 * �߽��ʶ��
 *
 * �����㷨: 8.1
 ===============*/

#ifndef BOUNDARYTAGMETHOD_H
#define BOUNDARYTAGMETHOD_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define e 5                        // ����ռ�ʱ�õ����ݲ�
#define FootLoc(p) p+(p->size)-1   // ��pָ�붨λ��p��ָ�ڴ��ĵײ�


/*
 * �ڴ�"��"�����Ͷ���
 *
 * ��ν"��"��ָ�ռ�������С��λ���������ֽڡ�
 * һ��"��"�ж��ȡ���ڶ�"��"�ṹ����ζ���ġ�
 */
typedef struct WORD {

    /*
     * ע��
     * �̲��н�llink��uplink��װ����һ���������У����˸о������װ��Щ���ߡ�
     * һ���棬head��foot�Ĺ���������ʵֻ��tag����������������壬��ôӦ����size��rlinkҲ��װ������
     * ��һ���棬�����װ��ʡ�Ŀռ�����ޣ�����ֱ��Ӱ���˴���Ŀɶ��ԡ�
     * ����ֻ�ǽ�ѧ���룬��������ʵ��ϵͳ���룬���Կռ俼������Σ�ԭ��չʾΪ��Ҫ����
     * ���⣬�̲��е�α����Ҳ��û�п�����������壬����ֱ�ӽ��в����ġ�
     * ��������������ȥ���˽̲��е�������ṹ��
     * ����۲�����������д�������Բο�CFree��֧�Ĵ��롣
     */

    int tag;             // ���־��0���У�1ռ�ã�ͷ����β������

    struct WORD* llink;  // ͷ����ָ��ǰ�����
    struct WORD* rlink;  // ͷ����ָ���̽��
    int size;            // ͷ���򣬿��С

    struct WORD* uplink; // �ײ���ָ�򱾽��ͷ��
} WORD;

typedef WORD* Space;     // Space��ָ������ÿռ��ָ������


/*
 * ��ʼ��һ���СΪn���ֵ��ڴ棬������ָ����ڴ������ָ��
 * ע�����صĳ�ʼ�ڴ��Ѿ�������head��foot��
 */
Space InitSpace(int n);

/*
 * ���������������� �㷨8.1 ����������������
 *
 * �߽��ʶ�����ڴ�����㷨
 *
 * �ӿռ�pav������һ���С����Ϊn�Ŀռ䣬������ָ�����뵽�Ŀռ��ָ�롣�������ʧ�ܣ��򷵻�NULL��
 * Ϊ��ʹ������ʣ��龡�����ȷֲ���ÿ�η�����֮��Ҫ�ѿռ�ָ��pav��ǰ�ƶ������������μ��̲ġ�
 *
 * ע��
 * 1.��������״���Ϸ�����һ���������������ڴ��ͽ��з��������
 * 2.Ϊ�˱���ռ���Ƭ�����죬����������һ���ݲ�e�����庬��ο��̲�������
 * 3.�����������n���ֵĿռ䣬ָ�����Ѿ���ɻ���Ŀռ䡣
 *   �����û���Ҫ����Ϊ10���ֵĿռ䣬��ÿ���ռ��ְ���head��foot�������ִ洢�ռ�ʹ����Ϣ��
 *   ���ʵ���Ϸ���Ŀռ��СӦΪ12���֣����"12"����n�ĺ��塣
 *   �̲����ᵽ"head��foot�ڷ���ʱ���Բ���"��������Ϊ��α����д�ķ��㡣ʵ��д����ʱ���������ռ��ǲ��ܺ��Եġ�
 *   ������������������������n����Ϊ�Ѿ������ռ䣬�������û�ԭʼ����Ŀռ䣬
 *   ��ô��������û�к��Կռ䣬��������������Ч���ϣ����̲�α��ͳһ����ν��ȫ������
 */
Space AllocBoundTag(Space* pav, int n);

/*
 * �߽��ʶ�����ڴ�����㷨
 *
 * ��ָ��p�����ڴ�����ͷ�
 */
void FreeBoundTag(Space* pav, Space p);

/*
 * ��ӡ�ڴ沼�֣��鿴��ǰ�ڴ��ʹ�����
 * ע�������ڲ�����ʹ��
 */
void PrintMemoryLayout();

/*
 * ������õĿ��пռ�����
 *
 * ע�������ڲ�ʹ�ã�������־��ӡ��
 */
static int AvailableSpace(Space pav);

#endif
