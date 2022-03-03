/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:55:35 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/03 14:58:09 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	mod(double i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	mul(float *x, float *y, float value)
{
	*x *= value;
	*y *= value;
}

unsigned int	minecraft_fade(int h)
{
	if (h > 70)
		return (0xE9EAF0);
	if (h > 62)
		return (0xC4C1BD);
	if (h > 50)
		return (0x4C591A);
	if (h > 10)
		return (0x4C591A);
	if (h > 1)
		return (0x4D5E36);
	if (h > 0)
		return (0xD8D19C);
	if (h > -5)
		return (0x444CC6);
	if (h > -10)
		return (0x2A2EAE);
	if (h > -30)
		return (0x3D497C);
	return (0x05093d);
}

unsigned int	test_fade(int h)
{
	if (h > 100)
		return (0x19323C);
	if (h > 75)
		return (0x25304B);
	if (h > 50)
		return (0x253C78);
	if (h > 25)
		return (0x54577C);
	if (h > 15)
		return (0x6969B3);
	if (h > 10)
		return (0x2292A4);
	if (h > 5)
		return (0x518AA8);
	if (h > 0)
		return (0x6699CC);
	if (h > -10)
		return (0x98C1D9);
	if (h > -20)
		return (0xF5B841);
	if (h > -50)
		return (0x9B3D12);
	return (0x650D1B);
}

unsigned int	fade(int h)
{
	if (h > 100)
		return (0xFFDF8D);
	if (h > 75)
		return (0xFFDE7A);
	if (h > 50)
		return (0xFFC568);
	if (h > 25)
		return (0xFD996B);
	if (h > 15)
		return (0xF7856C);
	if (h > 10)
		return (0xF06E6C);
	if (h > 5)
		return (0xD9576B);
	if (h > 0)
		return (0xA44369);
	if (h > -10)
		return (0x833F68);
	if (h > -20)
		return (0x833F68);
	if (h > -50)
		return (0x5E3C65);
	return (0x3F3A63);
}
