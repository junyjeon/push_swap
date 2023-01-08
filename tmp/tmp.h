/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:08:07 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/08 23:30:08 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For struct triangle
//# define MAX		(1)
//# define MIN		(0)
//# define INC		(1)
//# define DEC		(-1)
//# define IN_A		(1)
//# define IN_B		(-1)

/*struct 구조체이름 {
	반환값자료형 (*함수포인터명)(매개변수자료형1, 매개변수자료형2);
};
*/
// typedef struct s_command
// {
// 	int		(*fp[10])(void, void)={&sa, &sb, &ss, &pa, &pb, &ra, &rb, &rr, &rra, &rrb, &rrr};
// }	t_command;

//size and descending or ascending and stack a or b
//typedef struct s_triangle_map
//{
//	int	size;
//	int	inc_or_dec;
//	int	a_or_b;
//}	t_tri_map;

/* NOTE
 * ------------------------
 *                        |
 *       INC =    *       |
 *               /|       |
 *              / |       |
 *             /__|       |
 *                        |
 * ------------------------
 *                        |
 *       DEC = ____       |
 *             \  |       |
 *              \ |       |
 *               \|       |
 *                *       |
 * ------------------------
 * */
