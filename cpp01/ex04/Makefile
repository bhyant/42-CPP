# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/06 00:00:00 by tbhuiyan          #+#    #+#              #
#    Updated: 2026/01/06 02:21:36 by tbhuiyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = sed

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
DEPFLAGS    = -MMD -MP

SRC_DIR     = srcs
OBJ_DIR     = .objs
INC_DIR     = includes

INCLUDES    = -I$(INC_DIR)

SRCS        = $(SRC_DIR)/main.cpp

OBJS        = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS        = $(OBJS:.o=.d)

RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
CYAN        = \033[0;36m
RESET       = \033[0m

PROGRESS_BAR_WIDTH = 50
TOTAL_FILES = $(words $(OBJS))
CURRENT_FILE = 0

all: $(NAME)

$(NAME): $(OBJS)
	@echo ""
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_FILE)*100/$(TOTAL_FILES)))))
	@$(eval FILLED=$(shell echo $$(($(PERCENT)*$(PROGRESS_BAR_WIDTH)/100))))
	@$(eval EMPTY=$(shell echo $$(($(PROGRESS_BAR_WIDTH)-$(FILLED)))))
	@printf "\r$(CYAN)[$(GREEN)"
	@printf "%0.s=" $$(seq 1 $(FILLED))
	@printf "$(CYAN)%0.s " $$(seq 1 $(EMPTY))
	@printf "]$(RESET) $(PERCENT)%% Compiling: $(notdir $<)   "
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✓ Objects cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✓ Full clean done$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
