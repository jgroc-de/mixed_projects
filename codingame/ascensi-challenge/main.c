#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define F 0.9
#define MAX_SPEED 106
#define LEFT 400
#define RIGHT 9600
#define DOWN 400
#define UP 7600


/*
 * struct
*/
typedef struct  s_coord
{
    int x;
    int y;
}               t_coord;

typedef struct  s_ovni
{
    t_coord p;
    t_coord v;
    t_coord a;
	int speed;
    int boost;
    int flag;
    int side;
}               t_ovni;

/*
 * misc
*/
void printc(t_coord test)
{
	printf("(%d, %d)\n", test.x, test.y);
}

int	isneg(int value)
{
	if (value < 0)
		return (1);
	else
		return (0);
}

t_coord add(t_coord p1, t_coord p2)
{
	t_coord out;

	out.x = p1.x + p2.x;
	out.y = p1.y + p2.y;
	return (out);
}

t_coord sub(t_coord p1, t_coord p2)
{
	t_coord out;

	out.x = p1.x - p2.x;
	out.y = p1.y - p2.y;
	return (out);
}

t_coord mult(t_coord p1, int i)
{
	t_coord out;

	out.x = p1.x * i;
	out.y = p1.y * i;
	return (out);
}

t_coord divc(t_coord p1, double i)
{
	t_coord out;

	if (i != 0)
	{
		out.x = round(p1.x / i);
		out.y = round(p1.y / i);
	}
	return (out);
}

t_coord swap(t_coord p1)
{
	t_coord save;

	save = p1;
	p1.x = p1.y;
	p1.y = save.x;
	if (save.x && save.y)
	{
		p1.x *= (save.x * save.y) / (abs(save.x) * abs(save.y));
		p1.y *= (save.x * save.y) / (abs(save.x) * abs(save.y));
	}
	return (p1);
}

//a reteste et a transformer en int
int norme2(t_coord dest, t_coord src)
{
	t_coord out;
    
    out = sub(dest, src);
    return (((int)hypot(out.x, out.y)));
}

t_coord norme100(t_coord dest)
{
	t_coord zero = {};

	return (divc(mult(dest, 100), norme2(dest, zero)));
}

void print_ans(t_ovni me[2], int turn)
{
	t_coord v = {};
	//t_coord zero = {};
	int i;

	i = 0;
	while (i < 2)
	{
		v = add(me[i].a, me[i].p);
		//fprintf(stderr, "%d %d\n", i, me[i].boost);
		if ((me[i].speed == 500 && !(me[i].boost)) || !turn)
		{
			me[i].boost = 8;
			printf("%d %d BOOST\n", v.x, v.y);
			//printf("%d %d BOOST LOL! %d %f\n", v.x, v.y, me[i].boost, norme2(me[i].v, zero));
		}
		else
		{
			if (me[i].speed > 100)
				me[i].speed = 100;
			//printf("%d %d %d charge %d %f!\n", v.x, v.y, me[i].speed, me[i].boost, norme2(me[i].v, zero));
			printf("%d %d %d\n", v.x, v.y, me[i].speed);
		}
		i++;
	}
}

void manage_boost(t_ovni ovni[2])
{
	int i;

    i = 0;
    while (i < 2)
    {
        if (ovni[i].boost)
            ovni[i].boost--;
		i++;
	}
}

/*
 * récupération des variables de jeu
*/
void init(t_ovni ovni[2])
{
    for (int i = 0; i < 2; i++)
    {
        if (ovni[i].side == -1)
		{
			if (ovni[i].p.x <  4000)
            	ovni[i].side = 0;
			else
            	ovni[i].side = 10000;
		}
        ovni[i].boost = 0;
    }
}

void get_param(t_coord *flag, t_coord *enemyFlag, t_ovni me[2], t_ovni p2[2])
{
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
			&(flag->x),
			&(flag->y),
			&(enemyFlag->x),
			&(enemyFlag->y),
			&(me[0].p.x),
			&(me[0].p.y),
			&(me[0].v.x),
			&(me[0].v.y),
			&(me[0].flag),
			&(me[1].p.x),
			&(me[1].p.y),
			&(me[1].v.x),
			&(me[1].v.y),
			&(me[1].flag),
			&(p2[0].p.x),
			&(p2[0].p.y),
			&(p2[0].v.x),
			&(p2[0].v.y),
			&(p2[0].flag),
			&(p2[1].p.x),
			&(p2[1].p.y),
			&(p2[1].v.x),
			&(p2[1].v.y),
			&(p2[1].flag));
}

/*
 * aux fonction de vitesse
*/
t_coord	bordure(t_coord dest)
{
	t_coord out;

	out = dest;
	if (dest.x > RIGHT)
	{
		out.x = 2 * RIGHT - dest.x;
	}
	else if (dest.x < LEFT)
	{
		out.x = 2 * LEFT - dest.x;
	}
	if (dest.y > UP)
	{
		out.y = 2 * UP - dest.y;
	}
	else if (dest.y < DOWN)
	{
		out.y = 2 * DOWN - dest.y;
	}
	return (out);
}

t_coord prediction_p(t_ovni ovni, int turn)
{
	t_coord	out;

	//out = p + v * F * i + a * i^2;
	out = add(ovni.p, divc(mult(ovni.v, F * 10 * turn), 10));
	out = add(out, mult(ovni.a, pow(turn, 2)));
	out = bordure(out);
	return (out);
}

t_coord prediction_pf(t_ovni ovni, int turn)
{
	t_coord	out;

	//out = p + v * F * i + a * i^2;
	out = add(ovni.p, divc(mult(ovni.v, F * 10 * turn), 10));
	out = add(out, mult(ovni.a, pow(turn, 2)));
	return (out);
}

//still bad?
int isaxe(t_coord p1, t_coord p2, t_coord v)
{
	t_coord alpha;
	t_coord beta;
	int dist;
	int tmp;
	int tmp2;

	dist = norme2(p1, p2);
	if (dist == 0)
		dist = 1;
	alpha = norme100(sub(p2, p1));
	beta = norme100(v);
	if ((tmp = norme2(alpha, beta)) < (tmp2 = (314 * 80000 / (180 * dist))))
	{
	//	fprintf(stderr, " -- axe!! --\n");
		return (1);
	}
	else
	{
	//	fprintf(stderr, "tmp: %d\n", tmp);
	//	fprintf(stderr, "tmp2: %d\n", tmp2);
		return (0);
	}
}

/*
 * aux fonction d'actions
*/
t_coord miroir_flag(t_ovni me, t_ovni p2, t_coord flag)
{
	int c1;
	int c2;
	int c3;

	//si on va du bon coté
	c1 = (isneg(me.p.x - flag.x) == isneg(me.v.x));
	//si on est pas dans la bande
	c2 = abs(me.p.x - p2.side > 1000);
	c3 = abs(me.p.x - me.side > 1000);
	if ((c1 && c2) || (!c1 && !c2))
	{
		flag.x = flag.x > 4000 ? 2 * RIGHT - flag.x : LEFT - flag.x;
	}
	else if (c3 && !c1)
	{
		flag.x = flag.x > 4000 ? - flag.x : 19000;
	}
	//fprintf(stderr, "miroir : (%d, %d)\n", flag.x, flag.y);
	return (flag);
}

int	get_carry(t_ovni p2[2])
{
	if (p2[0].flag)
		return (0);
	else
		return (1);
}

int get_attacker(t_coord flag, t_ovni ovni[2])
{
    int i;
	int j[2];
	t_coord position;
	double norme;

	i = 0;
	while (i < 2)
	{
		j[i] = 1;
		while (j[i] < 6)
		{
			position = prediction_p(ovni[i], j[i]);
			norme = norme2(position, flag);
			if (norme < 2000)
				break;
			j[i] = j[i] + 1;
		}
		i++;
	}
	if (j[0] < j[1])
		i = 0;
	else
		i = 1;
	if (j[i] == 6)
		return (-1);
	return (i);
}

int get_defender(t_coord flag, t_coord enemyFlag, t_ovni me[2], t_ovni p2[2])
{
	int i;

	if (enemyFlag.x == -1)
	{
		return (me[0].flag ? 1 : 0);
	}
	else if (flag.x == -1)
	{
		i = get_carry(p2);
		if (norme2(p2[i].p, me[0].p) < norme2(p2[i].p, me[1].p))
			i = 0;
		else
			i = 1;
	}
	else
	{
		i = get_attacker(flag, me);
	}
	if (i == -1)
	{
		if (norme2(flag, me[0].p) < norme2(flag, me[1].p))
			i = 0;
		else
			i = 1;
	}
	return (i);
}

int headToFlag(t_ovni *p1, t_coord dest, t_coord *out)
{
    t_coord acc = {};
    t_coord zero = {};
	int i;
    
	i = 1;
	while (i < 30)
	{
		acc = divc(sub(dest, prediction_pf(*p1, i)), pow(i, 2));
		//rajouter une moyenne
		p1->speed = norme2(acc, zero);
		if (p1->speed <= MAX_SPEED)
			break ;
		i++;
	}
	*out = acc;
    return (i);
}

int intercept(t_ovni *p1, t_ovni p2, t_coord *out, int mode)
{
    t_coord acc = {};
    t_coord zero = {};
	t_coord tmp = {};
	int i;
    
	i = 1;
	while (i < 30)
	{
		/*
		 * p1 + v1*t + a1*t^2 = p2 + v2*t + a2*t^2
		 * a1 = (((p2 - p1) + (v2 - v1)*t) + a2*t^2)/t^2
		 */
		tmp = add(prediction_p(p2, i), mult(norme100(p2.v), 4));
		acc = divc(sub(tmp, prediction_p(*p1, i)), pow(i, 2));
		//rajouter une moyenne
		p1->speed = norme2(acc, zero);
		if (mode && p1->boost == 0 && p1->speed < 600 && p1->speed > 200)
		{
			p1->speed = 500;
			i *= i;
			break ;
		}
		else if (p1->speed < 110)
		{
			p1->speed = 100;
			break ;
		}
		i++;
	}
	*out = acc;
	return (i);
}

/*
 * actions
*/
int attack(t_coord enemyFlag, t_ovni *me, t_ovni p2[2])
{
	t_coord zero = {};

	if (norme2(enemyFlag, p2[0].p) < norme2(enemyFlag, p2[1].p))
		i = 0;
	else
		i = 1;
	if (abs(me->p.x - p2[i].side) > 1000 && norme2(enemyFlag, p2[i].p) < norme2(enemyFlag, me->p))
	{
		enemyFlag.x = p2[i].side == 10000 ? 8000 : 2000
		enemyFlag.y = 4000;
	}
	else
		enemyFlag = miroir_flag(*me, p2[0], enemyFlag);
	//chaotic is better? a sup?
	me->a = sub(enemyFlag, me->p);
	//headToFlag(me, enemyFlag, &(me->a));
	me->speed = 500;
	return (1);
}

//tester defense sur node
int defense(t_coord flag, t_coord enemyFlag, t_ovni *me, t_ovni p2[2])
{
    int i;
	int j;
	t_coord tmp;
    
	//fprintf(stderr, "defense sur node %d a (%d, %d)!\n", i, p2[i].p.x, p2[i].p.y);
    i = 0;
	if (flag.x != -1)
		i = get_attacker(flag, p2);
	else
		i = get_carry(p2);
	if (i == -1)
	{
		if (norme2(p2[0].p, me->p) < norme2(p2[1].p, me->p))
			i = 0;
		else
			i = 1;

	}
	if (flag.x != -1)
	{
    	intercept(me, p2[i], &(me->a), 0);
	}
	else
	{
    	j = intercept(me, p2[i], &(me->a), 1);
	}
	return (1);
}

t_coord axe(t_ovni me, t_ovni p2, t_coord v)
{
	int k;
	int i;
	t_coord tmp;

	k = 5;
	me.v = v;
	tmp = prediction_p(p2, intercept(&me, p2, &tmp, 0));
	if (p2.v.y)
		i = 30 * p2.v.y / abs(p2.v.y);
	else
		i = 30;
	while (k-- && isaxe(me.p, tmp, me.v))
	{
		if (p2.v.y)
			me.v.y -= i;
		else
			me.v.y -= i;
	}
	return (me.v);
}/*
t_coord axe(t_ovni me, t_ovni p2, t_coord v)
{
	int i;
	t_coord tmp1;
	t_coord tmp2;
	int dist;
	int save;

	i = 0;
	me.v = v;
	dist = norme2(prediction_p(me, i), prediction_p(p2, i));
	save = dist + 1;
	while (dist < save && i < 4)
	{
		i++;
		save = dist;
		dist = norme2(prediction_p(me, i), prediction_p(p2, i));
	}
	tmp1 = norme100(sub(p2.p, me.p));
	tmp2 = norme100(p2.v);
	if (dist < 1000)
	{
		fprintf(stderr, "axe:(%d, %d)\n", p2.p.x, p2.p.y);
		if (abs(tmp1.x - tmp2.x) < 10 && abs(tmp1.y - tmp2.y) < 10)
		{
			me.v.y = -p2.v.x;
			me.v.x = -p2.v.y;
		}
		else
		{
			me.v.x = -p2.v.x;
			me.v.y = -p2.v.y;
		}
	}
	return (me.v);
}
int getback(t_ovni me[2], t_ovni p2[2], int i)
{
	t_coord v;

	//fprintf(stderr, "get back\n");
	v = me[i].v;
	if (abs(v.y) >= (2 * abs(v.x)) / 3)
		v = swap(v);
	if (!(abs(me[i].p.x - p2[0].side) < 1000 && isneg(v.x) != isneg(me[0].side - p2[0].side)))
	{
		v = norme100(v);
		if (abs(me[i].p.x - me[i].side) > abs(p2[0].p.x - me[i].side))
			v = axe(*me, p2[0], v);
		if (abs(me[i].p.x - me[i].side) > abs(p2[1].p.x - me[i].side))
			v = axe(*me, p2[1], v);
		if (isneg(v.x) != isneg(me[0].side - me[i].p.x))
			v.x = -v.x;
	}
	me[i].a = v;
	return (1);
}*/
int getback(t_ovni me[2], t_ovni p2[2], int i)
{
	t_coord v;

	//fprintf(stderr, "get back\n");
	v = me[i].v;
	if (abs(v.y) >= (2 * abs(v.x)) / 3) 
		v = swap(v);
	v = norme100(v);
	//rajouter correction pour obstacle
	//fprintf(stderr, "e0\n");
	v = axe(*me, p2[0], v);
//	fprintf(stderr, "e1\n");
	v = axe(*me, p2[1], v);
//	fprintf(stderr, "me\n");
	v = axe(*me, me[i ? 0 : 1], v);
	me[i].a = v;
	return (1);
}

/*
 * main
*/
void action(t_coord flag, t_coord enemyFlag, t_ovni me[2], t_ovni p2[2])
{
    int i;
	int j;
	int k;
	t_coord tmp;
    
	i = get_defender(flag, enemyFlag, me, p2);
	//fprintf(stderr, "node %d turn!\n", i);
	defense(flag, enemyFlag, &(me[i]), p2);
	i = i ? 0 : 1;
	if (me[i].flag)
		getback(me, p2, i);
	else if (flag.x == -1 && intercept(&(me[i]), p2[get_carry(p2)], &tmp, 0) < 7)
	{
		/*k = get_carry(p2);
    	j = intercept(me, p2[k], &(me[i].a), 1);
		tmp = prediction_pf(*me, j);
		if ((tmp.x > 9000 || tmp.x < 1000) && j < me[i].boost)
		{
			if (enemyFlag.x != -1)
				attack(enemyFlag, &(me[i]), p2);
			else
				intercept(me, p2[k ? 0 : 1], &(me[i].a), 1);
		}
		else*/
		defense(flag, enemyFlag, &(me[i]), p2);
	}
	else
		attack(enemyFlag, &(me[i]), p2);
	//else if (flag.x == -1 && intercept(&(me[i]), p2[get_carry(p2)], &tmp, 0) < 6)
}

void	set_a(t_ovni p2[2], t_ovni me[2], t_coord eSpeed[2])
{
	int i;
	t_coord zero = {};

	i = 0;
	while (i < 2)
	{
		p2[i].a = divc(mult(p2[i].v, 100), norme2(p2[i].v, zero));
		//p2[i].a = divc(mult(sub(p2[i].v, mult(eSpeed[i], F)), 100), norme2(p2[i].v, zero));
		eSpeed[i] = p2[i].v;
		me[i].a = zero;
		me[i].speed = 100;
		i++;
	}
}

int main()
{
    t_coord flag;
    t_coord enemyFlag;
    t_ovni me[2] = {{.side = -1}, {.side = -1}};
    t_ovni p2[2] = {{.side = -1}, {.side = -1}};
	t_coord enemySpeed[2] = {};
	int i;
    
	i = 0;
	get_param(&flag, &enemyFlag, me, p2);
	init(me);
	init(p2);
	set_a(p2, me, enemySpeed);
	while (1)
	{
		manage_boost(me);
		action(flag, enemyFlag, me, p2);
		print_ans(me, i);
		get_param(&flag, &enemyFlag, me, p2);
		set_a(p2, me, enemySpeed);
		i++;
	}
	return 0;
}