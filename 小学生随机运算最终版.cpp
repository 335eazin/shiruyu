/*�١��ܹ��Զ���������������ϰ�⣻
�ڡ����Զ�����Ŀ������
�ۡ��û�����ѡ���������
�ܡ��û��������������ʮ���ڡ������ڵȣ���
�ݡ��û�ѡ���Ƿ������š��Ƿ���С����
�ޡ��û�ѡ�������ʽ����������ļ�����ӡ���ȣ���
�ߡ�������ṩͼ���û����棨�����Լ�����ѡ�����������������Ϊ����*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

static void enter(int i, int j) {
	if (i % j == 0) {
		printf("\n");
	}
}//����ÿ����ʾj������ʽ
static void grade1(int i,int j) {
	while (1) {
		int x = rand() % 2 + 1;//�������1��2
		int a = rand() % j;//�������С��20������
		int b = rand() % j;
		if (x == 1 && a + b < j) {
			printf("%03d��%d+%d\t\t", i, a, b);
			enter(i, 5);
			break;
		}
		if (x == 2 && a - b >= 0) {
			printf("%03d��%d-%d\t\t", i, a, b);
			enter(i, 5);
			break;
		}
	}
}//һ�꼶����Ŀ���ӷ��������0<=������<20��0<=���<20
static void grade2(int i,int j) {
	while (1) {
		int x1 = rand() % 2 + 1;
		int x2 = rand() % 2 + 1;
		int a = rand() % j;
		int b = rand() % j;
		int c = rand() % j;
		if (x1 == 1 && x2 == 2 && a + b - c >= 0 && a + b - c < j) {
			printf("%03d��%d+%d-%d\t\t", i, a, b, c);
			enter(i, 5);
			break;
		}
		if (x1 == 2 && x2 == 1 && a - b + c >= 0 && a - b + c < j) {
			printf("%03d��%d-%d+%d\t\t", i, a, b, c);
			enter(i, 5);
			break;
		}
	}
}//���꼶����Ŀ���Ӽ����
static void grade3(int i,int j) {
	while (1) {
		int x1 = rand() % 3 + 1;
		int x2 = rand() % 3 + 1;
		int x3 = rand() % 3 + 1;
		int a = rand() % j;
		int b = rand() % j;
		int c = rand() % j;
		int d = rand() % j;
		if (x1 == 1 && x2 == 2 && x3 == 3 && a + b - c * d >= 0) {
			printf("%03d��%d+%d-%d*%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//�Ӽ���
		if (x1 == 1 && x2 == 3 && x3 == 2 && a + b * c - d >= 0) {
			printf("%03d��%d+%d*%d-%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//�ӳ˼�
		if (x1 == 2 && x2 == 1 && x3 == 3 && a - b + c * d >= 0) {
			printf("%03d��%d-%d+%d*%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//���ӳ�
		if (x1 == 2 && x2 == 3 && x3 == 1 && a - b * c + d >= 0) {
			printf("%03d��%d-%d*%d+%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//���˼�
		if (x1 == 3 && x2 == 1 && x3 == 2 && a * b + c - d >= 0) {
			printf("%03d��%d*%d+%d-%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//�˼Ӽ�
		if (x1 == 3 && x2 == 2 && x3 == 1 && a * b - c + d >= 0) {
			printf("%03d��%d*%d-%d+%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//�˼���
	}
}//���꼶����Ŀ���Ӽ��˻�ϣ�������<1000
static void gradeL456(int i,int j) {
	while (1) {
		int x1 = rand() % 4 + 1;
		int x2 = rand() % 4 + 1;
		int x3 = rand() % 4 + 1;
		int x4 = rand() % 4 + 1;
		float o = rand() % 3 + 1;//��������λ��
		float a = (rand() % (j * 1000 + 1)) / 1000.0;
		float b = (rand() % (j * 1000 + 1)) / 1000.0;
		float c = (rand() % (j * 1000 + 1)) / 1000.0;
		float d = (rand() % (j * 1000 + 1)) / 1000.0;
		if (x1 == 1 && x2 == 2 && x3 == 3) {
			if (o == 1 && (a + b - c) * d >= 0) {
				printf("%03d��(%.3f+%.3f-%.3f)*%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a + (b - c) * d >= 0) {
				printf("%03d��%.3f+(%.3f-%.3f)*%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//123;
		if (x1 == 1 && x2 == 2 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a + b - c) / (float)d >= 0) {
					printf("%03d��(%.3f+%.3f-%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a + (b - c) / (float)d >= 0) {
					printf("%03d��%.3f+(%.3f-%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//124;
		if (x1 == 1 && x2 == 3 && x3 == 2) {
			if (o == 1 && (a + b) * c - d >= 0) {
				printf("%03d��(%.3f+%.3f)*%.3f-%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a + b * (c - d) >= 0) {
				printf("%03d��%.3f+%.3f*(%.3f-%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//132;
		if (x1 == 1 && x2 == 3 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a + b) * c / (float)d >= 0) {
					printf("%03d��(%.3f+%.3f)*%.3f/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && (a + b * c) / (float)d >= 0) {
					printf("%03d��(%.3f+%.3f*%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//134;
		if (x1 == 1 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //��ֹ/0
				if (o == 1 && (a + b) / (float)c - d >= 0) {
					printf("%03d��(%.3f+%.3f)/%.3f-%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a + b / ((float)c - d) >= 0) {
					printf("%03d��%.3f+%.3f/(%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//142;
		if (x1 == 1 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //��ֹ/0
				if (o == 1 && (a + b) / (float)c * d >= 0) {
					printf("%03d��(%.3f+%.3f)/%.3f*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && (a + b / (float)c) * d >= 0) {
					printf("%03d��(%.3f+%.3f/%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a + b / ((float)c * d) >= 0) {
					printf("%03d��%.3f+%.3f/(%.3f*%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//143;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 2 && x2 == 1 && x3 == 3) {
			if (o == 1 && (a - b + c) * d >= 0) {
				printf("%03d��(%.3f-%.3f+%.3f)*%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a - (b + c) * d >= 0) {
				printf("%03d��%.3f-(%.3f+%.3f)*%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 3 && a - (b + c * d) >= 0) {
				printf("%03d��%.3f-(%.3f+%.3f*%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//213;
		if (x1 == 2 && x2 == 1 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a - b + c) / (float)d >= 0) {
					printf("%03d��(%.3f-%.3f+%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a - (b + c) / (float)d >= 0) {
					printf("%03d��%.3f-(%.3f+%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a - (b + c / (float)d) >= 0) {
					printf("%03d��%.3f-(%.3f+%.3f/%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//214;
		if (x1 == 2 && x2 == 3 && x3 == 1) {
			if (o == 1 && (a - b) * c + d >= 0) {
				printf("%03d��(%.3f-%.3f)*%.3f+%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a - (b * c + d) >= 0) {
				printf("%03d��%.3f-(%.3f*%.3f+%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 3 && a - b * (c + d) >= 0) {
				printf("%03d��%.3f-%.3f*(%.3f+%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//231;
		if (x1 == 2 && x2 == 3 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a - b) * c / (float)d >= 0) {
					printf("%03d��(%.3f-%.3f)*%.3f/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && (a - b * c) / (float)d >= 0) {
					printf("%03d��(%.3f-%.3f*%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//234;
		if (x1 == 2 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //��ֹ/0
				if (o == 1 && (a - b) / (float)c + d >= 0) {
					printf("%03d��(%.3f-%.3f)/%.3f+%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a - (b / (float)c + d) >= 0) {
					printf("%03d��%.3f-(%.3f/%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a - b / ((float)c + d) >= 0) {
					printf("%03d��%.3f-%.3f/(%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//241;
		if (x1 == 2 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //��ֹ/0
				if (o == 1 && (a - b) / (float)c * d >= 0) {
					printf("%03d��(%.3f-%.3f)/%.3f*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && (a - b / (float)c) * d >= 0) {
					printf("%03d��(%.3f-%.3f/%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a - b / ((float)c * d) >= 0) {
					printf("%03d��%.3f-%.3f/(%.3f*%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//243;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 3 && x2 == 1 && x3 == 2) {
			if (o == 1 && a * (b + c) - d >= 0) {
				printf("%03d��%.3f*(%.3f+%.3f)-%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a * (b + c - d) >= 0) {
				printf("%03d��%.3f*(%.3f+%.3f-%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//312;
		if (x1 == 3 && x2 == 1 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a * b + c) / (float)d >= 0) {
					printf("%03d��(%.3f*%.3f+%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a * (b + c) / (float)d >= 0) {
					printf("%03d��%.3f*(%.3f+%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a * (b + c / (float)d) >= 0) {
					printf("%03d��%.3f*(%.3f+%.3f/%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//314;
		if (x1 == 3 && x2 == 2 && x3 == 1) {
			if (o == 1 && a * (b - c) + d >= 0) {
				printf("%03d��%.3f*(%.3f-%.3f)+%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a * (b - c + d) >= 0) {
				printf("%03d��%.3f*(%.3f-%.3f+%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 3 && a * b - (c + d) >= 0) {
				printf("%03d��%.3f*%.3f-(%.3f+%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//321;
		if (x1 == 3 && x2 == 2 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a * b - c) / (float)d >= 0) {
					printf("%03d��(%.3f*%.3f-%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a * (b - c) / (float)d >= 0) {
					printf("%03d��%.3f*(%.3f-%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a * (b - c / (float)d) >= 0) {
					printf("%03d��%.3f*(%.3f-%.3f/%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//324;
		if (x1 == 3 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //��ֹ/0
				if (o == 1 && a * (b / (float)c + d) >= 0) {
					printf("%03d��%.3f*(%.3f/%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a * b / ((float)c + d) >= 0) {
					printf("%03d��%.3f*%.3f/(%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//341;
		if (x1 == 3 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //��ֹ/0
				if (o == 1 && a * (b / (float)c - d) >= 0) {
					printf("%03d��%.3f*(%.3f/%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a * b / ((float)c - d) >= 0) {
					printf("%03d��%.3f*%.3f/(%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//342;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 4 && x2 == 1 && x3 == 2) {
			if (b + c != 0 && b + c - d != 0) { //��ֹ/0
				if (o == 1 && a / ((float)b + c) - d >= 0) {
					printf("%03d��%.3f/(%.3f+%.3f)-%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b + c - d) >= 0) {
					printf("%03d��%.3f/(%.3f+%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//412;
		if (x1 == 4 && x2 == 1 && x3 == 3) {
			if (b != 0 && b + c != 0 && b + c * d != 0) { //��ֹ/0
				if (o == 1 && (a / (float)b + c) * d >= 0) {
					printf("%03d��(%.3f/%.3f+%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b + c) * d >= 0) {
					printf("%03d��%.3f/(%.3f+%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / ((float)b + c * d) >= 0) {
					printf("%03d��%.3f/(%.3f+%.3f*%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//413;
		if (x1 == 4 && x2 == 2 && x3 == 1) {
			if (b - c != 0 && b - c + d != 0 && b != 0) { //��ֹ/0
				if (o == 1 && a / ((float)b - c) + d >= 0) {
					printf("%03d��%.3f/(%.3f-%.3f)+%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b - c + d) >= 0) {
					printf("%03d��%.3f/(%.3f-%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / (float)b - (c + d) >= 0) {
					printf("%03d��%.3f/%.3f-(%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//421;
		if (x1 == 4 && x2 == 2 && x3 == 3) {
			if (b != 0 && b - c != 0 && b - c * d != 0) { //��ֹ/0
				if (o == 1 && (a / (float)b - c) * d >= 0) {
					printf("%03d��(%.3f/%.3f-%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b - c) * d >= 0) {
					printf("%03d��%.3f/(%.3f-%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / ((float)b - c * d) >= 0) {
					printf("%03d��%.3f/(%.3f-%.3f*%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//423;
		if (x1 == 4 && x2 == 3 && x3 == 1) {
			if (b * c != 0 && b * c + d != 0 && b != 0) { //��ֹ/0
				if (o == 1 && a / ((float)b * c) + d >= 0) {
					printf("%03d��%.3f/(%.3f*%.3f)+%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b * c + d) >= 0) {
					printf("%03d��%.3f/(%.3f*%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / (float)b * (c + d) >= 0) {
					printf("%03d��%.3f/%.3f*(%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//431;
		if (x1 == 4 && x2 == 3 && x3 == 2) {
			if (b * c != 0 && b * c - d != 0 && b != 0) { //��ֹ/0
				if (o == 1 && a / ((float)b * c) - d >= 0) {
					printf("%03d��%.3f/(%.3f*%.3f)-%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b * c - d) >= 0) {
					printf("%03d��%.3f/(%.3f*%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / (float)b * (c - d) >= 0) {
					printf("%03d��%.3f/%.3f*(%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//432;
	}
}//С��456
static void grade456(int i,int j) {
	while (1) {
		int x1 = rand() % 4 + 1;
		int x2 = rand() % 4 + 1;
		int x3 = rand() % 4 + 1;
		int x4 = rand() % 4 + 1;
		int o = rand() % 3 + 1;//��������λ��
		int a = rand() % j;
		int b = rand() % j;
		int c = rand() % j;
		int d = rand() % j;
		if (x1 == 1 && x2 == 2 && x3 == 3) {
			if (o == 1 && (a + b - c) * d >= 0) {
				printf("%03d��(%d+%d-%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a + (b - c) * d >= 0) {
				printf("%03d��%d+(%d-%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//123;
		if (x1 == 1 && x2 == 2 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a + b - c) / (float)d >= 0) {
					printf("%03d��(%d+%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a + (b - c) / (float)d >= 0) {
					printf("%03d��%d+(%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//124;
		if (x1 == 1 && x2 == 3 && x3 == 2) {
			if (o == 1 && (a + b) * c - d >= 0) {
				printf("%03d��(%d+%d)*%d-%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a + b * (c - d) >= 0) {
				printf("%03d��%d+%d*(%d-%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//132;
		if (x1 == 1 && x2 == 3 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a + b) * c / (float)d >= 0) {
					printf("%03d��(%d+%d)*%d/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a + b * c) / (float)d >= 0) {
					printf("%03d��(%d+%d*%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//134;
		if (x1 == 1 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //��ֹ/0
				if (o == 1 && (a + b) / (float)c - d >= 0) {
					printf("%03d��(%d+%d)/%d-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a + b / ((float)c - d) >= 0) {
					printf("%03d��%d+%d/(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//142;
		if (x1 == 1 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //��ֹ/0
				if (o == 1 && (a + b) / (float)c * d >= 0) {
					printf("%03d��(%d+%d)/%d*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a + b / (float)c) * d >= 0) {
					printf("%03d��(%d+%d/%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a + b / ((float)c * d) >= 0) {
					printf("%03d��%d+%d/(%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//143;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 2 && x2 == 1 && x3 == 3) {
			if (o == 1 && (a - b + c) * d >= 0) {
				printf("%03d��(%d-%d+%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a - (b + c) * d >= 0) {
				printf("%03d��%d-(%d+%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a - (b + c * d) >= 0) {
				printf("%03d��%d-(%d+%d*%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//213;
		if (x1 == 2 && x2 == 1 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a - b + c) / (float)d >= 0) {
					printf("%03d��(%d-%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a - (b + c) / (float)d >= 0) {
					printf("%03d��%d-(%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - (b + c / (float)d) >= 0) {
					printf("%03d��%d-(%d+%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//214;
		if (x1 == 2 && x2 == 3 && x3 == 1) {
			if (o == 1 && (a - b) * c + d >= 0) {
				printf("%03d��(%d-%d)*%d+%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a - (b * c + d) >= 0) {
				printf("%03d��%d-(%d*%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a - b * (c + d) >= 0) {
				printf("%03d��%d-%d*(%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//231;
		if (x1 == 2 && x2 == 3 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a - b) * c / (float)d >= 0) {
					printf("%03d��(%d-%d)*%d/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a - b * c) / (float)d >= 0) {
					printf("%03d��(%d-%d*%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//234;
		if (x1 == 2 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //��ֹ/0
				if (o == 1 && (a - b) / (float)c + d >= 0) {
					printf("%03d��(%d-%d)/%d+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a - (b / (float)c + d) >= 0) {
					printf("%03d��%d-(%d/%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - b / ((float)c + d) >= 0) {
					printf("%03d��%d-%d/(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//241;
		if (x1 == 2 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //��ֹ/0
				if (o == 1 && (a - b) / (float)c * d >= 0) {
					printf("%03d��(%d-%d)/%d*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a - b / (float)c) * d >= 0) {
					printf("%03d��(%d-%d/%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - b / ((float)c * d) >= 0) {
					printf("%03d��%d-%d/(%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//243;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 3 && x2 == 1 && x3 == 2) {
			if (o == 1 && a * (b + c) - d >= 0) {
				printf("%03d��%d*(%d+%d)-%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a * (b + c - d) >= 0) {
				printf("%03d��%d*(%d+%d-%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//312;
		if (x1 == 3 && x2 == 1 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a * b + c) / (float)d >= 0) {
					printf("%03d��(%d*%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * (b + c) / (float)d >= 0) {
					printf("%03d��%d*(%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a * (b + c / (float)d) >= 0) {
					printf("%03d��%d*(%d+%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//314;
		if (x1 == 3 && x2 == 2 && x3 == 1) {
			if (o == 1 && a * (b - c) + d >= 0) {
				printf("%03d��%d*(%d-%d)+%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a * (b - c + d) >= 0) {
				printf("%03d��%d*(%d-%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a * b - (c + d) >= 0) {
				printf("%03d��%d*%d-(%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//321;
		if (x1 == 3 && x2 == 2 && x3 == 4) {
			if (d != 0) { //��ֹ/0
				if (o == 1 && (a * b - c) / (float)d >= 0) {
					printf("%03d��(%d*%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * (b - c) / (float)d >= 0) {
					printf("%03d��%d*(%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a * (b - c / (float)d) >= 0) {
					printf("%03d��%d*(%d-%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//324;
		if (x1 == 3 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //��ֹ/0
				if (o == 1 && a * (b / (float)c + d) >= 0) {
					printf("%03d��%d*(%d/%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * b / ((float)c + d) >= 0) {
					printf("%03d��%d*%d/(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//341;
		if (x1 == 3 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //��ֹ/0
				if (o == 1 && a * (b / (float)c - d) >= 0) {
					printf("%03d��%d*(%d/%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * b / ((float)c - d) >= 0) {
					printf("%03d��%d*%d/(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//342;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 4 && x2 == 1 && x3 == 2) {
			if (b + c != 0 && b + c - d != 0) { //��ֹ/0
				if (o == 1 && a / ((float)b + c) - d >= 0) {
					printf("%03d��%d/(%d+%d)-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b + c - d) >= 0) {
					printf("%03d��%d/(%d+%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//412;
		if (x1 == 4 && x2 == 1 && x3 == 3) {
			if (b != 0 && b + c != 0 && b + c * d != 0) { //��ֹ/0
				if (o == 1 && (a / (float)b + c) * d >= 0) {
					printf("%03d��(%d/%d+%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b + c) * d >= 0) {
					printf("%03d��%d/(%d+%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / ((float)b + c * d) >= 0) {
					printf("%03d��%d/(%d+%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//413;
		if (x1 == 4 && x2 == 2 && x3 == 1) {
			if (b - c != 0 && b - c + d != 0 && b != 0) { //��ֹ/0
				if (o == 1 && a / ((float)b - c) + d >= 0) {
					printf("%03d��%d/(%d-%d)+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b - c + d) >= 0) {
					printf("%03d��%d/(%d-%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b - (c + d) >= 0) {
					printf("%03d��%d/%d-(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//421;
		if (x1 == 4 && x2 == 2 && x3 == 3) {
			if (b != 0 && b - c != 0 && b - c * d != 0) { //��ֹ/0
				if (o == 1 && (a / (float)b - c) * d >= 0) {
					printf("%03d��(%d/%d-%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b - c) * d >= 0) {
					printf("%03d��%d/(%d-%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / ((float)b - c * d) >= 0) {
					printf("%03d��%d/(%d-%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//423;
		if (x1 == 4 && x2 == 3 && x3 == 1) {
			if (b * c != 0 && b * c + d != 0 && b != 0) { //��ֹ/0
				if (o == 1 && a / ((float)b * c) + d >= 0) {
					printf("%03d��%d/(%d*%d)+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b * c + d) >= 0) {
					printf("%03d��%d/(%d*%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b * (c + d) >= 0) {
					printf("%03d��%d/%d*(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//431;
		if (x1 == 4 && x2 == 3 && x3 == 2) {
			if (b * c != 0 && b * c - d != 0 && b != 0) { //��ֹ/0
				if (o == 1 && a / ((float)b * c) - d >= 0) {
					printf("%03d��%d/(%d*%d)-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b * c - d) >= 0) {
					printf("%03d��%d/(%d*%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b * (c - d) >= 0) {
					printf("%03d��%d/%d*(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//432;
	}
}//�ĵ����꼶����Ŀ������������������ӼӼ��˳�����ѡ�����������ŵ�����ʽ

int main() {
	int a;//������Ŀѡ��
	int b;//������Ŀ����
	int c;//���ڽ�����ֵ
	srand(time(NULL));//���������
	while (1) {
		while (1) {
			printf("��ӭ�����������ϵͳ��������\n");
			printf("1.�ӷ����������\n2.�Ӽ����������\n3.�Ӽ��˷��������\n4.�����żӼ��˳��������\n5.�����ŵļӼ��˳�С���������\n6.�˳�ϵͳ\n");
			printf("����������ѡ����ţ�\n");
			if (scanf("%d", &a) == 1) {//����ѡ��
				if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5) {
					break;
				}
				else if (a == 6) {
					printf("��л����ʹ�ã�����\n");
					return 0;
				}
				else printf("��������������\n");
			}
			else {
				printf("��������������\n");//���������
				while (getchar() != '\n');
			}
		}
		while (1) {
			printf("���������������ֵ(�Ǹ�)��\n");
			if (scanf("%d", &c)) {
				if (c>0) {
					break;
				}
				else {
					printf("��������������\n");
				}
			}
			else {
				printf("��������������\n");//���������
				while (getchar() != '\n');
			}
		}
		while (1) {
			printf("��������Ŀ������\n");
			if (scanf("%d", &b)) {
				;//������Ŀ����
				break;
			}
			else {
				printf("����������������Ŀ����\n");
				while (getchar() != '\n');
			}
		}
		for (int i = 1; i <= b; i++) {
			if (a == 1) {
				grade1(i,c);
			}
			if (a == 2) {
				grade2(i,c);
			}
			if (a == 3) {
				grade3(i,c);
			}
			if (a == 4) {
				grade456(i, c);
			}
			if (a == 5) {
				gradeL456(i,c);
			}
		}
		int n;
		while (1) {
			printf("\n��ѡ�������ʽ��1.������ļ�  2.�������ӡ��\n");
			if (scanf("%d", &n)) {
			if (n == 1){
				printf("��Ŀ�ɹ�������ļ���\n");
				break;
				}
				else if(n==2){
				printf("��Ŀ�ɹ��������ӡ����\n");
				break;
				}
				else 
					printf("��������������\n");
				}
			else {
				printf("��������������\n");//���������
				while (getchar() != '\n');
			}
		}
		
		for (int o = 0; o < 120; o++) {
			printf("-");
		}
	}
}
