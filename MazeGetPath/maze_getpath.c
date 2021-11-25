#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 110

typedef struct Position
{
    int row; // ��
    int col; // ��
}PT; // ����

/*--------------------------------------*/
typedef struct stack
{
    PT* Path;
    int top;
    int capacity;
}stack;

void initStack(stack* s)
{
    s->Path = (PT*)malloc(sizeof(PT) * MAX_SIZE);
    s->capacity = MAX_SIZE;
    s->top = 0;
}

int IsEmpty(stack* s)
{
    return s->top == 0 ? 1 : 0;
}

void push(stack* s, PT cur)
{
    s->Path[s->top] = cur;
    s->top++;
}

void pop(stack* s)
{
    if (!IsEmpty(s))
    {
        s->top--;
    }
}

PT Top(stack* s)
{
    return s->Path[s->top - 1];
}

void Destory(stack* s)
{
    free(s->Path);
    s->Path = NULL;
    s->capacity = s->top = 0;
}

stack path;
/*-------------------------------------*/
void Print(int** a, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void PrintPath()
{
    stack rPath; // ����rPathջ��·���ϵĵ㵹��ȥ�����ջ
    initStack(&rPath);
    while (!IsEmpty(&path))
    {
        PT cur = Top(&path);
        push(&rPath, cur);
        pop(&path);
    }

    Destory(&path);

    while (!IsEmpty(&rPath))
    {
        PT cur = Top(&rPath);
        printf("(%d,%d)\n", cur.row, cur.col);
        pop(&rPath);
    }

    Destory(&rPath);
}

int IsPass(int** maze, int N, int M, PT cur) // ����ͨ��
{
    if (cur.row >= 0 && cur.row < N
        && cur.col >= 0 && cur.col < M
        && maze[cur.row][cur.col] == 0)
    {
        return 1; // ����ͨ��
    }
    else
    {
        return 0; // ������ͨ��
    }
}

int GetMazePath(int** maze, int N, int M, PT cur)
{
    // ���Ǽ�����һ���ǰ�����·����---������������ѹ��ջ
    // �õ�ֻ������״̬
    // 1. ������·����  2. ��������·����
    // ���1�����Ѿ�ѹ��ջ��
    // ���2��return false ֮ǰ�����ջ��
    // ����ȷ��ջ���Ԫ�ؾ���·����ÿ���������
    push(&path, cur);
    if (cur.row == N - 1 && cur.col == M - 1)
    {
        return 1; // �ҵ����յ�
    }
    PT next = cur;
    // ���е���������һ������Ч��
    maze[cur.row][cur.col] = 2; // ��־���ѷ��� ��0 -- �յأ�1 -- ǽ��2 -- �ѱ����ʣ�


    // ��
    next = cur;
    next.row -= 1; // cur�Ϸ�������
    if (IsPass(maze, N, M, next))
    {
        if (GetMazePath(maze, N, M, next))// �ݹ���������
        {
            return 1;
        }
    }

    // ��
    next = cur;
    next.row += 1; // cur�·�������
    if (IsPass(maze, N, M, next))
    {
        if (GetMazePath(maze, N, M, next))// �ݹ���������
        {
            return 1;
        }
    }

    // ��
    next = cur;
    next.col -= 1; // cur�󷽵�����
    if (IsPass(maze, N, M, next))
    {
        if (GetMazePath(maze, N, M, next))// �ݹ���������
        {
            return 1;
        }
    }

    // ��
    next = cur;
    next.col += 1; // cur�ҷ�������
    if (IsPass(maze, N, M, next))
    {
        if (GetMazePath(maze, N, M, next))// �ݹ���������
        {
            return 1;
        }
    }
    pop(&path);
    return 0; // �ĸ����������ͨ��������һ������
}


int main()
{
    int N = 0, M = 0;
    while (scanf("%d %d", &N, &M) != EOF)
    {
        // ��̬���ٶ�ά����
        int** maze = (int**)malloc(sizeof(int*) * N);
        for (int i = 0; i < N; i++)
        {
            maze[i] = (int*)malloc(sizeof(int) * M);
        }

        // ¼���Թ�
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &maze[i][j]);
            }
        }
        // �Բ���������
        //Print(maze, N, M);

        // �������
        PT entry = { 0, 0 }; // ���
        initStack(&path);
        int flag = GetMazePath(maze, N, M, entry);

        if (flag)
        {
            //printf("11");
            printf("���Թ������ڵ�·��Ϊ��\n");
            PrintPath();
        }
        else
        {
            printf("���Թ�û�е����ڵ�·����");
        }

        // �ͷŶ�̬���ٵĿռ�
        for (int i = 0; i < N; i++)
        {
            free(maze[i]);
        }
        free(maze);
        maze = NULL;
    }

    return 0;
}