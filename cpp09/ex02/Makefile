# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/23 10:54:51 by tbhuiyan          #+#    #+#              #
#    Updated: 2026/04/23 10:55:05 by tbhuiyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := PmergeMe
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98
RM          := rm -rf

SRC_DIR     := srcs
OBJ_DIR     := .obj
INC_DIR     := includes

SRCS        := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJS        := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS        := $(OBJS:.o=.d)

DEPFLAGS    := -MMD -MP -I $(INC_DIR)

TOTAL       := $(words $(SRCS))
COUNT       := 0

GREEN       := \033[1;32m
CYAN        := \033[1;36m
BLUE        := \033[1;34m
RESET       := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "\n$(GREEN)✅ $(NAME) compilé avec succès !$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@awk -v c=$(COUNT) -v t=$(TOTAL) -v src=$< 'BEGIN { \
		p = int((c / t) * 100); \
		b = int((c / t) * 30); \
		bar = ""; \
		for (i = 0; i < b; i++) bar = bar "█"; \
		for (i = b; i < 30; i++) bar = bar "░"; \
		printf "\r\033[K\033[1;34m[\033[1;32m%s\033[1;34m]\033[1;36m %3d%%\033[0m %s", bar, p, src; \
	}'
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(CYAN)🧹 Objets et dépendances supprimés.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)🗑️ Exécutable supprimé.$(RESET)"

re: fclean all

debug: CXXFLAGS += -g3 -fsanitize=address
debug: re
	@echo "$(GREEN)🐛 Mode DEBUG (fsanitize) activé !$(RESET)"

help:
	@echo "$(CYAN)make$(RESET)        : Compile"
	@echo "$(CYAN)make clean$(RESET)  : Supprime $(OBJ_DIR)"
	@echo "$(CYAN)make fclean$(RESET) : Supprime $(OBJ_DIR) et $(NAME)"
	@echo "$(CYAN)make re$(RESET)     : Recompile"
	@echo "$(CYAN)make debug$(RESET)  : Compile avec fsanitize"

-include $(DEPS)

.PHONY: all clean fclean re debug help
