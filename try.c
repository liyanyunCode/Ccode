#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int map[100][100] = { 0 };///map[i][j]Ϊ0��ʾi, j����֮�䲻ͨ��Ϊ1��ʾ��һ��·
int stack[120], v[100] = { 0 }, top = 0, m, n, start, end;
void dfs(int pos)//��pos�㿪ʼ����
{
    int i;
    if (pos == end) {//�����յ�
        for (i = 0; i < top; i++)
            printf("%d -��", stack[i]);
        printf("%d\n", end);
        return;
    }
    v[pos] = 1;//��Ǳ����ʹ� 
    stack[top++] = pos;//������·���������
    for (i = 1; i <= n; i++) {
        if (!v[i] && map[pos][i])//��������û�б����ʹ�������pos��������������ͼ�������
            dfs(i);
    }
    v[pos] = 0;//ɾ����� 
    top--;//������ɾ��pos
}

int main()
{
    int i, x, y;
    printf("�ֱ����붥����n��·����m��");
    scanf("%d %d", &n, &m);//n�Ƕ�������m�Ǳ��� 

    printf("����m��·����");
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        map[x][y] = 1;//������֮����·��
        map[y][x] = 1; //��Ϊ������ͼ����Ҫ˫���� 
    }

    printf("������ʼ����յ㣺");
    scanf("%d %d", &start, &end);

    printf("\n����ִ�н��Ϊ��\n");
    dfs(start);
    return 0;

}
