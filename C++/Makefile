EXAMPLE = EXAMPLE394

# 设置编译器选项
CXXFLAGS = -std=c++11
# 设置预处理器选项
CPPFLAGS = -D EXAMPLE=$(EXAMPLE)

PROGRAM = $(EXAMPLE)

# 设置编译器
CXX = clang++

RM = rm -f

SRCS = Main.cpp
OBJS = $(SRCS:.cpp=.o)

PHONY += all
all: $(PROGRAM)

# $@ 代表目标文件，在这里即 $(PROGRAM)；$^ 代表所有源文件，在这里即 $(OBJS)。
$(PROGRAM): $(OBJS)
	$(CXX) -o $@ $^

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $^

PHONY += clean
clean:
	$(RM) $(OBJS)

PHONY += all-clean
all-clean: clean
	$(RM) $(PROGRAM)

# 伪目标，防止 make 执行的命令与实际文件名冲突。
.PHONY: $(PHONY)
