# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolopez <lolopez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 17:48:27 by lolopez           #+#    #+#              #
#    Updated: 2020/04/17 18:11:40 by lolopez          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

INC=%%%%

INCLIB=$(INC)/minilibx-linux/lib

INCLUDES = cub3d.h ./getnextline/get_next_line.h

CC=clang

SRC_PATH = ./

PRINTF_PATH = ./printf

MLX_PATH = ./minilibx-linux

LIBFTPRINTF = $(PRINTF_PATH)/libftprintf.a

MLX = $(MLX_PATH)/libmlx_Linux.a

SRCS = 	$(addprefix ./srcs/, bmp.c\
		calculs_2.c\
		calculs.c\
		create_img.c\
		cub_error.c\
		error_management.c\
		event_1.c\
		event_2.c\
		free_all.c\
		get_map_colors.c\
		get_map_res.c\
		get_map_text.c\
		get_map.c\
		init_cub_1.c\
		key.c\
		map_error.c\
		map_init.c\
		minimap_img.c\
		print_map.c\
		print_walls.c\
		raycast_sprite_1.c\
		raycast_sprite_2.c\
		raycast_sprite_math.c\
		print_sprite.c\
		raycast_wall_2.c\
		raycast_wall.c\
		raycast.c\
		read_map.c\
		sort_sprite.c\
		bonus_img.c\
		bonusgame.c\
		)\
		$(addprefix ./getnextline/, get_next_line.c\
		get_next_line_utils.c)

MAIN = main.c

MAIN_B = main_bonus.c

OBJ := ${SRCS:.c=.o} ${MAIN:.c=.o}

OBJ_B:= ${SRCS:.c=.o} ${MAIN_B:.c=.o}

all : make_lib ${NAME}

$(NAME):${OBJ}
	@$(CC) -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH) -lmlx_Linux -L$(INCLIB) -lXext -lX11 -lm -lbsd
	make parrot
	make instruction

bonus: fclean make_lib $(OBJ_B)
	@$(CC) -Wall -Wextra -Werror -o $(NAME) $(OBJ_B) -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH) -lmlx_Linux -L$(INCLIB) -lXext -lX11 -lm -lbsd
	make parrot
	make instruction

make_lib:
	@make -C $(PRINTF_PATH)
	@make -C $(MLX_PATH)

clean:
	@make fclean -C $(PRINTF_PATH)
	@make clean -C $(MLX_PATH)
	@rm -f ${OBJ} ${OBJ_B}

fclean: clean
	@rm -f ${NAME}


re: fclean all

instruction:
	@echo " "
	@echo "\033[0;31m /!\ WARNING /!\ \033[0m"
	@echo " "
	@echo "\033[0;31m This program is made for AZERTY KEYBOARD \033[0m"
	@echo "\033[0;31m Please feel free to change the key code event in the cub3d.h file \033[0m"
	@echo "\033[0;31m to know what code event you need : just add 'printf("%x\n", keycode);' in the keypress function, reload the program and try pushing the key \033[0m"
	@echo "\033[0;31m You'll find this function in the ./srcs/event_2.c file \033[0m"
	@echo "\033[0;31m eNJoY <3 \033[0m"
	@echo " "

parrot:
	@echo "	                	    .cccc;;cc;';c.           "
	@echo "                      .,:dkdc:;;:c:,:d:.          "
	@echo "              	   .loc'.,cc::c:::,..;:.         "
	@echo "                   .cl;....;dkdccc::,...c;        "
	@echo "                  .c:,';:'..ckc',;::;....;c.      "
	@echo "                .c:'.,dkkoc:ok:;llllc,,c,';:.     "
	@echo "               .;c,';okkkkkkkk:;lllll,:kd;.;:,.   "
	@echo "               co..:kkkkkkkkkk:;llllc':kkc..oNc   "
	@echo "             .cl;.,oxkkkkkkkkkc,:cll;,okkc'.cO;   "
	@echo "             ;k:..ckkkkkkkkkkkl..,;,.;xkko:',l'   "
	@echo "            .,...';dkkkkkkkkkkd;.....ckkkl'.cO;   "
	@echo "         .,,:,.;oo:ckkkkkkkkkkkdoc;;cdkkkc..cd,   "
	@echo "      .cclo;,ccdkkl;llccdkkkkkkkkkkkkkkkd,.c;     "
	@echo "     .lol:;;okkkkkxooc::coodkkkkkkkkkkkko'.oc     "
	@echo "   .c:'..lkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd,.oc     "
	@echo "  .lo;,:cdkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd,.c;     "
	@echo ",dx:..;lllllllllllllllllllllllllllllllllc'...     "
	@echo "cNO;........................................      "
	sleep 0.02
	clear
	@echo "                                                  "
	@echo "                                                  "
	@echo "                .ckx;'........':c.                "
	@echo "             .,:c:::::oxxocoo::::,',.             "
	@echo "            .odc'..:lkkoolllllo;..;d,             "
	@echo "            ;c..:o:..;:..',;'.......;.            "
	@echo "           ,c..:0Xx::o:.,cllc:,'::,.,c.           "
	@echo "           ;c;lkXKXXXXl.;lllll;lKXOo;':c.         "
	@echo "         ,dc.oXXXXXXXXl.,lllll;lXXXXx,c0:         "
	@echo "         ;Oc.oXXXXXXXXo.':ll:;'oXXXXO;,l'         "
	@echo "         'l;;kXXXXXXXXd'.'::'..dXXXXO;,l'         "
	@echo "         'l;:0XXXXXXXX0x:...,:o0XXXXx,:x,         "
	@echo "         'l;;kXXXXXXXXXKkol;oXXXXXXXO;oNc         "
	@echo "        ,c'..ckk0XXXXXXXXXX00XXXXXXX0:;o:.        "
	@echo "      .':;..:do::ooookXXXXXXXXXXXXXXXo..c;        "
	@echo "    .',',:co0XX0kkkxxOXXXXXXXXXXXXXXXOc..;l.      "
	@echo "  .:;'..oXXXXXXXXXXXXXXXXXXXXXXXXXXXXXko;';:.     "
	@echo ".ldc..:oOXKXXXXXXKXXKXXXXXXXXXXXXXXXXXXXo..oc     "
	@echo ":0o...:dxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxo,.:,     "
	@echo "cNo........................................;'     "
	sleep 0.02
	clear
	@echo "                                                  "
	@echo "            .cc;.  ...  .;c.                      "
	@echo "         .,,cc:cc:lxxxl:ccc:;,.                   "
	@echo "        .lo;...lKKklllookl..cO;                   "
	@echo "      .cl;.,:'.okl;..''.;,..';:.                  "
	@echo "     .:o;;dkd,.ll..,cc::,..,'.;:,.                "
	@echo "     co..lKKKkokl.':lloo;''ol..;dl.               "
	@echo "   .,c;.,xKKKKKKo.':llll;.'oOxl,.cl,.             "
	@echo "   cNo..lKKKKKKKo'';llll;;okKKKl..oNc             "
	@echo "   cNo..lKKKKKKKko;':c:,'lKKKKKo'.oNc             "
	@echo "   cNo..lKKKKKKKKKl.....'dKKKKKxc,l0:             "
	@echo "   .c:'.lKKKKKKKKKk;....lKKKKKKo'.oNc             "
	@echo "     ,:.'oxOKKKKKKKOxxxxOKKKKKKxc,;ol:.           "
	@echo "     ;c..'':oookKKKKKKKKKKKKKKKKKk:.'clc.         "
	@echo "   ,xl'.,oxo;'';oxOKKKKKKKKKKKKKKKOxxl:::;,.      "
	@echo "  .dOc..lKKKkoooookKKKKKKKKKKKKKKKKKKKxl,;ol.     "
	@echo "  cx,';okKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKl..;lc.   "
	@echo "  co..:dddddddddddddddddddddddddddddddddl::',::.  "
	@echo "  co........................................... "
	sleep 0.02
	clear
	@echo "                                                  "
	@echo "           .ccccccc.                              "
	@echo "      .,,,;cooolccoo;;,,.                         "
	@echo "     .dOx;..;lllll;..;xOd.                        "
	@echo "   .cdo;',loOXXXXXkll;';odc.                      "
	@echo "  ,ol:;c,':oko:cccccc,...ckl.                     "
	@echo "  ;c.;kXo..::..;c::'.......oc                     "
	@echo ",dc..oXX0kk0o.':lll;..cxxc.,ld,                   "
	@echo "kNo.'oXXXXXXo',:lll;..oXXOo;cOd.                  "
	@echo "KOc;oOXXXXXXo.':lol;..dXXXXl';xc                  "
	@echo "Ol,:k0XXXXXX0c.,clc'.:0XXXXx,.oc                  "
	@echo "KOc;dOXXXXXXXl..';'..lXXXXXo..oc                  "
	@echo "dNo..oXXXXXXXOx:..'lxOXXXXXk,.:; ..               "
	@echo "cNo..lXXXXXXXXXOolkXXXXXXXXXkl,..;:';.            "
	@echo ".,;'.,dkkkkk0XXXXXXXXXXXXXXXXXOxxl;,;,;l:.        "
	@echo "  ;c.;:''''':doOXXXXXXXXXXXXXXXXXXOdo;';clc.      "
	@echo "  ;c.lOdood:'''oXXXXXXXXXXXXXXXXXXXXXk,..;ol.     "
	@echo "  ';.:xxxxxocccoxxxxxxxxxxxxxxxxxxxxxxl::'.';;.   "
	@echo "  ';........................................;l'   "
	sleep 0.02
	clear
	@echo "	                                                 "
	@echo "        .;:;;,.,;;::,.                            "
	@echo "     .;':;........'co:.                           "
	@echo "   .clc;'':cllllc::,.':c.                         "
	@echo "  .lo;;o:coxdllllllc;''::,,.                      "
	@echo ".c:'.,cl,.'l:',,;;'......cO;                      "
	@echo "do;';oxoc;:l;;llllc'.';;'.,;.                     "
	@echo "c..ckkkkkkkd,;llllc'.:kkd;.':c.                   "
	@echo "'.,okkkkkkkkc;lllll,.:kkkdl,cO;                   "
	@echo "..;xkkkkkkkkc,ccll:,;okkkkk:,co,                  "
	@echo "..,dkkkkkkkkc..,;,'ckkkkkkkc;ll.                  "
	@echo "..'okkkkkkkko,....'okkkkkkkc,:c.                  "
	@echo "c..ckkkkkkkkkdl;,:okkkkkkkkd,.',';.               "
	@echo "d..':lxkkkkkkkkxxkkkkkkkkkkkdoc;,;'..'.,.         "
	@echo "o...'';llllldkkkkkkkkkkkkkkkkkkdll;..'cdo.        "
	@echo "o..,l;'''''';dkkkkkkkkkkkkkkkkkkkkdlc,..;lc.      "
	@echo "o..;lc;;;;;;,,;clllllllllllllllllllllc'..,:c.     "
	@echo "o..........................................;'     "
	sleep 0.02
	clear
	@echo "	                                                 "
	@echo "           .,,,,,,,,,.                            "
	@echo "         .ckKxodooxOOdcc.                         "
	@echo "      .cclooc'....';;cool.                        "
	@echo "     .loc;;;;clllllc;;;;;:;,.                     "
	@echo "   .c:'.,okd;;cdo:::::cl,..oc                     "
	@echo "  .:o;';okkx;';;,';::;'....,:,.                   "
	@echo "  co..ckkkkkddkc,cclll;.,c:,:o:.                  "
	@echo "  co..ckkkkkkkk:,cllll;.:kkd,.':c.                "
	@echo ".,:;.,okkkkkkkk:,cclll;.ckkkdl;;o:.               "
	@echo "cNo..ckkkkkkkkko,.;loc,.ckkkkkc..oc               "
	@echo ",dd;.:kkkkkkkkkx;..;:,.'lkkkkko,.:,               "
	@echo "  ;:.ckkkkkkkkkkc.....;ldkkkkkk:.,'               "
	@echo ",dc..'okkkkkkkkkxoc;;cxkkkkkkkkc..,;,.            "
	@echo "kNo..':lllllldkkkkkkkkkkkkkkkkkdcc,.;l.           "
	@echo "KOc,c;''''''';lldkkkkkkkkkkkkkkkkkc..;lc.         "
	@echo "xx:':;;;;,.,,...,;;cllllllllllllllc;'.;od,        "
	@echo "cNo.....................................oc        "                                          
	sleep 0.02
	clear
	@echo "                                                  "
	@echo "                                                  "
	@echo "                   .ccccccc.                      "
	@echo "               .ccckNKOOOOkdcc.                   "
	@echo "            .;;cc:ccccccc:,:c::,,.                "
	@echo "         .c;:;.,cccllxOOOxlllc,;ol.               "
	@echo "        .lkc,coxo:;oOOxooooooo;..:,               "
	@echo "      .cdc.,dOOOc..cOd,.',,;'....':l.             "
	@echo "      cNx'.lOOOOxlldOc..;lll;.....cO;             "
	@echo "     ,do;,:dOOOOOOOOOl'':lll;..:d:''c,            "
	@echo "     co..lOOOOOOOOOOOl'':lll;.'lOd,.cd.           "
	@echo "     co.'dOOOOOOOOOOOo,.;llc,.,dOOc..dc           "
	@echo "     co..lOOOOOOOOOOOOc.';:,..cOOOl..oc           "
	@echo "   .,:;.'::lxOOOOOOOOOo:'...,:oOOOc.'dc           "
	@echo "   ;Oc..cl'':lldOOOOOOOOdcclxOOOOx,.cd.           "
	@echo "  .:;';lxl''''':lldOOOOOOOOOOOOOOc..oc            "
	@echo ",dl,.'cooc:::,....,::coooooooooooc'.c:            "
	@echo "cNo.................................oc            "
	sleep 0.02
	clear
	@echo "                                                  "
	@echo "                                                  "
	@echo "                                                  "
	@echo "                                                  "
	@echo "                        .cccccccc.                "
	@echo "                  .,,,;;cc:cccccc:;;,.            "
	@echo "                .cdxo;..,::cccc::,..;l.           "
	@echo "               ,do:,,:c:coxxdllll:;,';:,.         "
	@echo "             .cl;.,oxxc'.,cc,.';;;'...oNc         "
	@echo "             ;Oc..cxxxc'.,c;..;lll;...cO;         "
	@echo "           .;;',:ldxxxdoldxc..;lll:'...'c,        "
	@echo "           ;c..cxxxxkxxkxxxc'.;lll:'','.cdc.      "
	@echo "         .c;.;odxxxxxxxxxxxd;.,cll;.,l:.'dNc      "
	@echo "        .:,''ccoxkxxkxxxxxxx:..,:;'.:xc..oNc      "
	@echo "      .lc,.'lc':dxxxkxxxxxxxol,...',lx:..dNc      "
	@echo "     .:,',coxoc;;ccccoxxxxxxxxo:::oxxo,.cdc.      "
	@echo "  .;':;.'oxxxxxc''''';cccoxxxxxxxxxxxc..oc        "
	@echo ",do:'..,:llllll:;;;;;;,..,;:lllllllll;..oc        "
	@echo "cNo.....................................oc        "
	sleep 0.02
	clear
	@echo "                                                  "
	@echo "                                                  "
	@echo "                              .ccccc.             "
	@echo "                         .cc;'coooxkl;.           "
	@echo "                     .:c:::c:,,,,,;c;;,.'.        "
	@echo "                   .clc,',:,..:xxocc;'..c;        "
	@echo "                  .c:,';:ox:..:c,,,,,,...cd,      "
	@echo "                .c:'.,oxxxxl::l:.,loll;..;ol.     "
	@echo "                ;Oc..:xxxxxxxxx:.,llll,....oc     "
	@echo "             .,;,',:loxxxxxxxxx:.,llll;.,,.'ld,   "
	@echo "            .lo;..:xxxxxxxxxxxx:.'cllc,.:l:'cO;   "
	@echo "           .:;...'cxxxxxxxxxxxxoc;,::,..cdl;;l'   "
	@echo "         .cl;':,'';oxxxxxxdxxxxxx:....,cooc,cO;   "
	@echo "     .,,,::;,lxoc:,,:lxxxxxxxxxxxo:,,;lxxl;'oNc   "
	@echo "   .cdxo;':lxxxxxxc'';cccccoxxxxxxxxxxxxo,.;lc.   "
	@echo "  .loc'.'lxxxxxxxxocc;''''';ccoxxxxxxxxx:..oc     "
	@echo "olc,..',:cccccccccccc:;;;;;;;;:ccccccccc,.'c,     "
	@echo "Ol;......................................;l'      "
	sleep 0.02
	clear
	@echo "                                                  "
	@echo "                              ,ddoodd,            "
	@echo "                         .cc' ,ooccoo,'cc.        "
	@echo "                      .ccldo;...',,...;oxdc.      "
	@echo "                   .,,:cc;.,'..;lol;;,'..lkl.     "
	@echo "                  .dOc';:ccl;..;dl,.''.....oc     "
	@echo "                .,lc',cdddddlccld;.,;c::'..,cc:.  "
	@echo "                cNo..:ddddddddddd;':clll;,c,';xc  "
	@echo "               .lo;,clddddddddddd;':clll;:kc..;'  "
	@echo "             .,c;..:ddddddddddddd:';clll,;ll,..   "
	@echo "             ;Oc..';:ldddddddddddl,.,c:;';dd;..   "
	@echo "           .''',:c:,'cdddddddddddo:,''..'cdd;..   "
	@echo "         .cdc';lddd:';lddddddddddddd;.';lddl,..   "
	@echo "      .,;::;,cdddddol;;lllllodddddddlcldddd:.'l;  "
	@echo "     .dOc..,lddddddddlcc:;'';cclddddddddddd;;ll.  "
	@echo "   .coc,;::ldddddddddddddlcccc:ldddddddddl:,cO;   "
	@echo ",xl::,..,cccccccccccccccccccccccccccccccc:;':xx,  "
	@echo "cNd.........................................;lOc  "

.PHONY: norm all re fclean clean progs bonus