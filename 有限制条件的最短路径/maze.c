#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
stack minpath;
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

void PrintPath(stack* ps)
{
    stack rPath;
    initStack(&rPath);
    while (!IsEmpty(ps))
    {
        PT cur = Top(ps);
        push(&rPath, cur);
        pop(ps);
    }

    while (!IsEmpty(&rPath))
    {
        PT cur = Top(&rPath);
        if (rPath.top == 1)
        {
            printf("[%d,%d]", cur.row, cur.col);
            pop(&rPath);
            continue;
        }

        printf("[%d,%d],", cur.row, cur.col);
        pop(&rPath);
    }

    Destory(&rPath);
}

int IsPass(int** maze, int N, int M, PT cur) // ����ͨ��
{
    if (cur.row >= 0 && cur.row < N
        && cur.col >= 0 && cur.col < M
        && maze[cur.row][cur.col] == 1)
    {
        return 1; // ����ͨ��
    }
    else
    {
        return 0; // ������ͨ��
    }
}

void copy(stack* ppath, stack* min)
{
    min->Path = (PT*)malloc(sizeof(PT) * ppath->capacity);
    memcpy(min->Path, ppath->Path, sizeof(PT) * ppath->top);
    min->capacity = ppath->capacity;
    min->top = ppath->top;
}
void GetMazePath(int** maze, int N, int M, int P, PT cur)
{
    push(&path, cur);

    // �ߵ�����
    if (cur.row == 0 && cur.col == M - 1)
    {
        if ((path.top < minpath.top
            || IsEmpty(&minpath)) && P >= 0) // �������·��
        {
            Destory(&minpath);
            copy(&path, &minpath);
        }
    }
    PT next = cur;
    // ���е���������һ������Ч��
    maze[cur.row][cur.col] = 2; // ��־���ѷ��� ��0 -- �յأ�1 -- ǽ��2 -- �ѱ����ʣ�


    // ��
    next = cur;
    next.row -= 1; // cur�Ϸ�������
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, P - 3, next);// �ݹ���������
    }

    // ��
    next = cur;
    next.row += 1; // cur�·�������
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, P, next);// �ݹ���������
    }

    // ��
    next = cur;
    next.col -= 1; // cur�󷽵�����
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, P - 1, next);// �ݹ���������
    }

    // ��
    next = cur;
    next.col += 1; // cur�ҷ�������
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, P - 1, next);// �ݹ���������
    }

    maze[cur.row][cur.col] = 1;
    pop(&path);
}

int main()
{
    int N = 0, M = 0, P = 0;
    while (scanf("%d %d %d", &N, &M, &P) != EOF)
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
        initStack(&minpath);
        GetMazePath(maze, N, M, P, entry);

        // ��ӡ·��
        if (!IsEmpty(&minpath))
        {
            PrintPath(&minpath);
        }
        else
        {
            printf("Can not escape!");
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