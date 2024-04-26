/*①　能够自动生成四则运算练习题；
②　可以定制题目数量；
③　用户可以选择运算符；
④　用户设置最大数（如十以内、百以内等）；
⑤　用户选择是否有括号、是否有小数；
⑥　用户选择输出方式（如输出到文件、打印机等）；
⑦　最好能提供图形用户界面（根据自己能力选做，以完成上述功能为主）*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

static void enter(int i, int j) {
	if (i % j == 0) {
		printf("\n");
	}
}//用于每行显示j个运算式
static void grade1(int i,int j) {
	while (1) {
		int x = rand() % 2 + 1;//随机生成1或2
		int a = rand() % j;//随机生成小于20的数字
		int b = rand() % j;
		if (x == 1 && a + b < j) {
			printf("%03d：%d+%d\t\t", i, a, b);
			enter(i, 5);
			break;
		}
		if (x == 2 && a - b >= 0) {
			printf("%03d：%d-%d\t\t", i, a, b);
			enter(i, 5);
			break;
		}
	}
}//一年级的题目，加法或减法，0<=运算数<20，0<=结果<20
static void grade2(int i,int j) {
	while (1) {
		int x1 = rand() % 2 + 1;
		int x2 = rand() % 2 + 1;
		int a = rand() % j;
		int b = rand() % j;
		int c = rand() % j;
		if (x1 == 1 && x2 == 2 && a + b - c >= 0 && a + b - c < j) {
			printf("%03d：%d+%d-%d\t\t", i, a, b, c);
			enter(i, 5);
			break;
		}
		if (x1 == 2 && x2 == 1 && a - b + c >= 0 && a - b + c < j) {
			printf("%03d：%d-%d+%d\t\t", i, a, b, c);
			enter(i, 5);
			break;
		}
	}
}//二年级的题目，加减混合
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
			printf("%03d：%d+%d-%d*%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//加减乘
		if (x1 == 1 && x2 == 3 && x3 == 2 && a + b * c - d >= 0) {
			printf("%03d：%d+%d*%d-%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//加乘减
		if (x1 == 2 && x2 == 1 && x3 == 3 && a - b + c * d >= 0) {
			printf("%03d：%d-%d+%d*%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//减加乘
		if (x1 == 2 && x2 == 3 && x3 == 1 && a - b * c + d >= 0) {
			printf("%03d：%d-%d*%d+%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//减乘加
		if (x1 == 3 && x2 == 1 && x3 == 2 && a * b + c - d >= 0) {
			printf("%03d：%d*%d+%d-%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//乘加减
		if (x1 == 3 && x2 == 2 && x3 == 1 && a * b - c + d >= 0) {
			printf("%03d：%d*%d-%d+%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//乘减加
	}
}//三年级的题目，加减乘混合，运算数<1000
static void gradeL456(int i,int j) {
	while (1) {
		int x1 = rand() % 4 + 1;
		int x2 = rand() % 4 + 1;
		int x3 = rand() % 4 + 1;
		int x4 = rand() % 4 + 1;
		float o = rand() % 3 + 1;//控制括号位置
		float a = (rand() % (j * 1000 + 1)) / 1000.0;
		float b = (rand() % (j * 1000 + 1)) / 1000.0;
		float c = (rand() % (j * 1000 + 1)) / 1000.0;
		float d = (rand() % (j * 1000 + 1)) / 1000.0;
		if (x1 == 1 && x2 == 2 && x3 == 3) {
			if (o == 1 && (a + b - c) * d >= 0) {
				printf("%03d：(%.3f+%.3f-%.3f)*%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a + (b - c) * d >= 0) {
				printf("%03d：%.3f+(%.3f-%.3f)*%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//123;
		if (x1 == 1 && x2 == 2 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a + b - c) / (float)d >= 0) {
					printf("%03d：(%.3f+%.3f-%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a + (b - c) / (float)d >= 0) {
					printf("%03d：%.3f+(%.3f-%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//124;
		if (x1 == 1 && x2 == 3 && x3 == 2) {
			if (o == 1 && (a + b) * c - d >= 0) {
				printf("%03d：(%.3f+%.3f)*%.3f-%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a + b * (c - d) >= 0) {
				printf("%03d：%.3f+%.3f*(%.3f-%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//132;
		if (x1 == 1 && x2 == 3 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a + b) * c / (float)d >= 0) {
					printf("%03d：(%.3f+%.3f)*%.3f/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && (a + b * c) / (float)d >= 0) {
					printf("%03d：(%.3f+%.3f*%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//134;
		if (x1 == 1 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //防止/0
				if (o == 1 && (a + b) / (float)c - d >= 0) {
					printf("%03d：(%.3f+%.3f)/%.3f-%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a + b / ((float)c - d) >= 0) {
					printf("%03d：%.3f+%.3f/(%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//142;
		if (x1 == 1 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //防止/0
				if (o == 1 && (a + b) / (float)c * d >= 0) {
					printf("%03d：(%.3f+%.3f)/%.3f*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && (a + b / (float)c) * d >= 0) {
					printf("%03d：(%.3f+%.3f/%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a + b / ((float)c * d) >= 0) {
					printf("%03d：%.3f+%.3f/(%.3f*%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//143;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 2 && x2 == 1 && x3 == 3) {
			if (o == 1 && (a - b + c) * d >= 0) {
				printf("%03d：(%.3f-%.3f+%.3f)*%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a - (b + c) * d >= 0) {
				printf("%03d：%.3f-(%.3f+%.3f)*%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 3 && a - (b + c * d) >= 0) {
				printf("%03d：%.3f-(%.3f+%.3f*%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//213;
		if (x1 == 2 && x2 == 1 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a - b + c) / (float)d >= 0) {
					printf("%03d：(%.3f-%.3f+%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a - (b + c) / (float)d >= 0) {
					printf("%03d：%.3f-(%.3f+%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a - (b + c / (float)d) >= 0) {
					printf("%03d：%.3f-(%.3f+%.3f/%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//214;
		if (x1 == 2 && x2 == 3 && x3 == 1) {
			if (o == 1 && (a - b) * c + d >= 0) {
				printf("%03d：(%.3f-%.3f)*%.3f+%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a - (b * c + d) >= 0) {
				printf("%03d：%.3f-(%.3f*%.3f+%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 3 && a - b * (c + d) >= 0) {
				printf("%03d：%.3f-%.3f*(%.3f+%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//231;
		if (x1 == 2 && x2 == 3 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a - b) * c / (float)d >= 0) {
					printf("%03d：(%.3f-%.3f)*%.3f/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && (a - b * c) / (float)d >= 0) {
					printf("%03d：(%.3f-%.3f*%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//234;
		if (x1 == 2 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //防止/0
				if (o == 1 && (a - b) / (float)c + d >= 0) {
					printf("%03d：(%.3f-%.3f)/%.3f+%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a - (b / (float)c + d) >= 0) {
					printf("%03d：%.3f-(%.3f/%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a - b / ((float)c + d) >= 0) {
					printf("%03d：%.3f-%.3f/(%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//241;
		if (x1 == 2 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //防止/0
				if (o == 1 && (a - b) / (float)c * d >= 0) {
					printf("%03d：(%.3f-%.3f)/%.3f*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && (a - b / (float)c) * d >= 0) {
					printf("%03d：(%.3f-%.3f/%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a - b / ((float)c * d) >= 0) {
					printf("%03d：%.3f-%.3f/(%.3f*%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//243;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 3 && x2 == 1 && x3 == 2) {
			if (o == 1 && a * (b + c) - d >= 0) {
				printf("%03d：%.3f*(%.3f+%.3f)-%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a * (b + c - d) >= 0) {
				printf("%03d：%.3f*(%.3f+%.3f-%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//312;
		if (x1 == 3 && x2 == 1 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a * b + c) / (float)d >= 0) {
					printf("%03d：(%.3f*%.3f+%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a * (b + c) / (float)d >= 0) {
					printf("%03d：%.3f*(%.3f+%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a * (b + c / (float)d) >= 0) {
					printf("%03d：%.3f*(%.3f+%.3f/%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//314;
		if (x1 == 3 && x2 == 2 && x3 == 1) {
			if (o == 1 && a * (b - c) + d >= 0) {
				printf("%03d：%.3f*(%.3f-%.3f)+%.3f\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 2 && a * (b - c + d) >= 0) {
				printf("%03d：%.3f*(%.3f-%.3f+%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
			if (o == 3 && a * b - (c + d) >= 0) {
				printf("%03d：%.3f*%.3f-(%.3f+%.3f)\t\t\t", i, a, b, c, d);
				enter(i, 2);
				break;
			}
		}//321;
		if (x1 == 3 && x2 == 2 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a * b - c) / (float)d >= 0) {
					printf("%03d：(%.3f*%.3f-%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a * (b - c) / (float)d >= 0) {
					printf("%03d：%.3f*(%.3f-%.3f)/%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a * (b - c / (float)d) >= 0) {
					printf("%03d：%.3f*(%.3f-%.3f/%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//324;
		if (x1 == 3 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //防止/0
				if (o == 1 && a * (b / (float)c + d) >= 0) {
					printf("%03d：%.3f*(%.3f/%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a * b / ((float)c + d) >= 0) {
					printf("%03d：%.3f*%.3f/(%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//341;
		if (x1 == 3 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //防止/0
				if (o == 1 && a * (b / (float)c - d) >= 0) {
					printf("%03d：%.3f*(%.3f/%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a * b / ((float)c - d) >= 0) {
					printf("%03d：%.3f*%.3f/(%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//342;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 4 && x2 == 1 && x3 == 2) {
			if (b + c != 0 && b + c - d != 0) { //防止/0
				if (o == 1 && a / ((float)b + c) - d >= 0) {
					printf("%03d：%.3f/(%.3f+%.3f)-%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b + c - d) >= 0) {
					printf("%03d：%.3f/(%.3f+%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//412;
		if (x1 == 4 && x2 == 1 && x3 == 3) {
			if (b != 0 && b + c != 0 && b + c * d != 0) { //防止/0
				if (o == 1 && (a / (float)b + c) * d >= 0) {
					printf("%03d：(%.3f/%.3f+%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b + c) * d >= 0) {
					printf("%03d：%.3f/(%.3f+%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / ((float)b + c * d) >= 0) {
					printf("%03d：%.3f/(%.3f+%.3f*%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//413;
		if (x1 == 4 && x2 == 2 && x3 == 1) {
			if (b - c != 0 && b - c + d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b - c) + d >= 0) {
					printf("%03d：%.3f/(%.3f-%.3f)+%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b - c + d) >= 0) {
					printf("%03d：%.3f/(%.3f-%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / (float)b - (c + d) >= 0) {
					printf("%03d：%.3f/%.3f-(%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//421;
		if (x1 == 4 && x2 == 2 && x3 == 3) {
			if (b != 0 && b - c != 0 && b - c * d != 0) { //防止/0
				if (o == 1 && (a / (float)b - c) * d >= 0) {
					printf("%03d：(%.3f/%.3f-%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b - c) * d >= 0) {
					printf("%03d：%.3f/(%.3f-%.3f)*%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / ((float)b - c * d) >= 0) {
					printf("%03d：%.3f/(%.3f-%.3f*%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//423;
		if (x1 == 4 && x2 == 3 && x3 == 1) {
			if (b * c != 0 && b * c + d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b * c) + d >= 0) {
					printf("%03d：%.3f/(%.3f*%.3f)+%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b * c + d) >= 0) {
					printf("%03d：%.3f/(%.3f*%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / (float)b * (c + d) >= 0) {
					printf("%03d：%.3f/%.3f*(%.3f+%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//431;
		if (x1 == 4 && x2 == 3 && x3 == 2) {
			if (b * c != 0 && b * c - d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b * c) - d >= 0) {
					printf("%03d：%.3f/(%.3f*%.3f)-%.3f\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 2 && a / ((float)b * c - d) >= 0) {
					printf("%03d：%.3f/(%.3f*%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
				if (o == 3 && a / (float)b * (c - d) >= 0) {
					printf("%03d：%.3f/%.3f*(%.3f-%.3f)\t\t\t", i, a, b, c, d);
					enter(i, 2);
					break;
				}
			}
		}//432;
	}
}//小数456
static void grade456(int i,int j) {
	while (1) {
		int x1 = rand() % 4 + 1;
		int x2 = rand() % 4 + 1;
		int x3 = rand() % 4 + 1;
		int x4 = rand() % 4 + 1;
		int o = rand() % 3 + 1;//控制括号位置
		int a = rand() % j;
		int b = rand() % j;
		int c = rand() % j;
		int d = rand() % j;
		if (x1 == 1 && x2 == 2 && x3 == 3) {
			if (o == 1 && (a + b - c) * d >= 0) {
				printf("%03d：(%d+%d-%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a + (b - c) * d >= 0) {
				printf("%03d：%d+(%d-%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//123;
		if (x1 == 1 && x2 == 2 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a + b - c) / (float)d >= 0) {
					printf("%03d：(%d+%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a + (b - c) / (float)d >= 0) {
					printf("%03d：%d+(%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//124;
		if (x1 == 1 && x2 == 3 && x3 == 2) {
			if (o == 1 && (a + b) * c - d >= 0) {
				printf("%03d：(%d+%d)*%d-%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a + b * (c - d) >= 0) {
				printf("%03d：%d+%d*(%d-%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//132;
		if (x1 == 1 && x2 == 3 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a + b) * c / (float)d >= 0) {
					printf("%03d：(%d+%d)*%d/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a + b * c) / (float)d >= 0) {
					printf("%03d：(%d+%d*%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//134;
		if (x1 == 1 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //防止/0
				if (o == 1 && (a + b) / (float)c - d >= 0) {
					printf("%03d：(%d+%d)/%d-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a + b / ((float)c - d) >= 0) {
					printf("%03d：%d+%d/(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//142;
		if (x1 == 1 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //防止/0
				if (o == 1 && (a + b) / (float)c * d >= 0) {
					printf("%03d：(%d+%d)/%d*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a + b / (float)c) * d >= 0) {
					printf("%03d：(%d+%d/%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a + b / ((float)c * d) >= 0) {
					printf("%03d：%d+%d/(%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//143;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 2 && x2 == 1 && x3 == 3) {
			if (o == 1 && (a - b + c) * d >= 0) {
				printf("%03d：(%d-%d+%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a - (b + c) * d >= 0) {
				printf("%03d：%d-(%d+%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a - (b + c * d) >= 0) {
				printf("%03d：%d-(%d+%d*%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//213;
		if (x1 == 2 && x2 == 1 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a - b + c) / (float)d >= 0) {
					printf("%03d：(%d-%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a - (b + c) / (float)d >= 0) {
					printf("%03d：%d-(%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - (b + c / (float)d) >= 0) {
					printf("%03d：%d-(%d+%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//214;
		if (x1 == 2 && x2 == 3 && x3 == 1) {
			if (o == 1 && (a - b) * c + d >= 0) {
				printf("%03d：(%d-%d)*%d+%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a - (b * c + d) >= 0) {
				printf("%03d：%d-(%d*%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a - b * (c + d) >= 0) {
				printf("%03d：%d-%d*(%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//231;
		if (x1 == 2 && x2 == 3 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a - b) * c / (float)d >= 0) {
					printf("%03d：(%d-%d)*%d/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a - b * c) / (float)d >= 0) {
					printf("%03d：(%d-%d*%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//234;
		if (x1 == 2 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //防止/0
				if (o == 1 && (a - b) / (float)c + d >= 0) {
					printf("%03d：(%d-%d)/%d+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a - (b / (float)c + d) >= 0) {
					printf("%03d：%d-(%d/%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - b / ((float)c + d) >= 0) {
					printf("%03d：%d-%d/(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//241;
		if (x1 == 2 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //防止/0
				if (o == 1 && (a - b) / (float)c * d >= 0) {
					printf("%03d：(%d-%d)/%d*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a - b / (float)c) * d >= 0) {
					printf("%03d：(%d-%d/%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - b / ((float)c * d) >= 0) {
					printf("%03d：%d-%d/(%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//243;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 3 && x2 == 1 && x3 == 2) {
			if (o == 1 && a * (b + c) - d >= 0) {
				printf("%03d：%d*(%d+%d)-%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a * (b + c - d) >= 0) {
				printf("%03d：%d*(%d+%d-%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//312;
		if (x1 == 3 && x2 == 1 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a * b + c) / (float)d >= 0) {
					printf("%03d：(%d*%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * (b + c) / (float)d >= 0) {
					printf("%03d：%d*(%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a * (b + c / (float)d) >= 0) {
					printf("%03d：%d*(%d+%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//314;
		if (x1 == 3 && x2 == 2 && x3 == 1) {
			if (o == 1 && a * (b - c) + d >= 0) {
				printf("%03d：%d*(%d-%d)+%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a * (b - c + d) >= 0) {
				printf("%03d：%d*(%d-%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a * b - (c + d) >= 0) {
				printf("%03d：%d*%d-(%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//321;
		if (x1 == 3 && x2 == 2 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a * b - c) / (float)d >= 0) {
					printf("%03d：(%d*%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * (b - c) / (float)d >= 0) {
					printf("%03d：%d*(%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a * (b - c / (float)d) >= 0) {
					printf("%03d：%d*(%d-%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//324;
		if (x1 == 3 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //防止/0
				if (o == 1 && a * (b / (float)c + d) >= 0) {
					printf("%03d：%d*(%d/%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * b / ((float)c + d) >= 0) {
					printf("%03d：%d*%d/(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//341;
		if (x1 == 3 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //防止/0
				if (o == 1 && a * (b / (float)c - d) >= 0) {
					printf("%03d：%d*(%d/%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * b / ((float)c - d) >= 0) {
					printf("%03d：%d*%d/(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//342;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 4 && x2 == 1 && x3 == 2) {
			if (b + c != 0 && b + c - d != 0) { //防止/0
				if (o == 1 && a / ((float)b + c) - d >= 0) {
					printf("%03d：%d/(%d+%d)-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b + c - d) >= 0) {
					printf("%03d：%d/(%d+%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//412;
		if (x1 == 4 && x2 == 1 && x3 == 3) {
			if (b != 0 && b + c != 0 && b + c * d != 0) { //防止/0
				if (o == 1 && (a / (float)b + c) * d >= 0) {
					printf("%03d：(%d/%d+%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b + c) * d >= 0) {
					printf("%03d：%d/(%d+%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / ((float)b + c * d) >= 0) {
					printf("%03d：%d/(%d+%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//413;
		if (x1 == 4 && x2 == 2 && x3 == 1) {
			if (b - c != 0 && b - c + d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b - c) + d >= 0) {
					printf("%03d：%d/(%d-%d)+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b - c + d) >= 0) {
					printf("%03d：%d/(%d-%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b - (c + d) >= 0) {
					printf("%03d：%d/%d-(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//421;
		if (x1 == 4 && x2 == 2 && x3 == 3) {
			if (b != 0 && b - c != 0 && b - c * d != 0) { //防止/0
				if (o == 1 && (a / (float)b - c) * d >= 0) {
					printf("%03d：(%d/%d-%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b - c) * d >= 0) {
					printf("%03d：%d/(%d-%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / ((float)b - c * d) >= 0) {
					printf("%03d：%d/(%d-%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//423;
		if (x1 == 4 && x2 == 3 && x3 == 1) {
			if (b * c != 0 && b * c + d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b * c) + d >= 0) {
					printf("%03d：%d/(%d*%d)+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b * c + d) >= 0) {
					printf("%03d：%d/(%d*%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b * (c + d) >= 0) {
					printf("%03d：%d/%d*(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//431;
		if (x1 == 4 && x2 == 3 && x3 == 2) {
			if (b * c != 0 && b * c - d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b * c) - d >= 0) {
					printf("%03d：%d/(%d*%d)-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b * c - d) >= 0) {
					printf("%03d：%d/(%d*%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b * (c - d) >= 0) {
					printf("%03d：%d/%d*(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//432;
	}
}//四到六年级的题目，带有三个运算符（从加减乘除中任选三个）和括号的运算式

int main() {
	int a;//用于题目选择
	int b;//用于题目数量
	int c;//用于结果最大值
	srand(time(NULL));//随机数种子
	while (1) {
		while (1) {
			printf("欢迎来到随机计算系统！！！！\n");
			printf("1.加法或减法运算\n2.加减法混合运算\n3.加减乘法混合运算\n4.带括号加减乘除混合运算\n5.带括号的加减乘除小数混合运算\n6.退出系统\n");
			printf("请输入您的选择序号：\n");
			if (scanf("%d", &a) == 1) {//输入选择
				if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5) {
					break;
				}
				else if (a == 6) {
					printf("感谢您的使用！！！\n");
					return 0;
				}
				else printf("错误，请重新输入\n");
			}
			else {
				printf("错误，请重新输入\n");//输入非数字
				while (getchar() != '\n');
			}
		}
		while (1) {
			printf("请输入运算结果最大值(非负)：\n");
			if (scanf("%d", &c)) {
				if (c>0) {
					break;
				}
				else {
					printf("错误，请重新输入\n");
				}
			}
			else {
				printf("错误，请重新输入\n");//输入非数字
				while (getchar() != '\n');
			}
		}
		while (1) {
			printf("请输入题目数量：\n");
			if (scanf("%d", &b)) {
				;//输入题目数量
				break;
			}
			else {
				printf("错误，请重新输入题目数量\n");
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
			printf("\n请选择输出方式：1.输出到文件  2.输出到打印机\n");
			if (scanf("%d", &n)) {
			if (n == 1){
				printf("题目成功输出到文件！\n");
				break;
				}
				else if(n==2){
				printf("题目成功输出到打印机！\n");
				break;
				}
				else 
					printf("错误，请重新输入\n");
				}
			else {
				printf("错误，请重新输入\n");//输入非数字
				while (getchar() != '\n');
			}
		}
		
		for (int o = 0; o < 120; o++) {
			printf("-");
		}
	}
}
