/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:20:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/23 18:22:44 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "bonus/includes/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

// カラーコード
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// テスト結果の追跡
int g_test_count = 0;
int g_test_passed = 0;

// 出力長さの比較と結果表示を拡張
void compare_length(int ft_len, int std_len, const char *test_name, const char *format, ...)
{
    g_test_count++;
    printf("テスト: [%s] - フォーマット: \"%s\"\n", test_name, format);
    printf("出力長さ: ft_printf=%d, printf=%d ", ft_len, std_len);
    
    if (ft_len == std_len)
    {
        printf("[%s OK %s]\n", GREEN, RESET);
        g_test_passed++;
    }
    else
        printf("[%s KO %s] - %s長さが異なります%s\n", RED, RESET, RED, RESET);
}

// 各種フォーマット指定子のテスト
void test_format_specifiers(void)
{
    int ft_len;
    int std_len;
    char *format;
    
    printf("\n%s===== フォーマット指定子のテスト =====%s\n", BLUE, RESET);
    
    // %c テスト
    printf("\n%s----- %%c テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %c\n";
    printf("入力: \"%s\", 文字='A'\n", format);
    ft_len = ft_printf(format, 'A');
    std_len = printf("printf:    %c\n", 'A');
    compare_length(ft_len, std_len, "%c", format);
    
    // %s テスト
    printf("\n%s----- %%s テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %s\n";
    printf("入力: \"%s\", 文字列=\"Hello World\"\n", format);
    ft_len = ft_printf(format, "Hello World");
    std_len = printf("printf:    %s\n", "Hello World");
    compare_length(ft_len, std_len, "%s", format);
    
    // %p テスト
    int num = 42;
    printf("\n%s----- %%p テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %p\n";
    printf("入力: \"%s\", ポインタ=&num\n", format);
    ft_len = ft_printf(format, &num);
    std_len = printf("printf:    %p\n", &num);
    compare_length(ft_len, std_len, "%p", format);
    
    // %d テスト
    printf("\n%s----- %%d テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %d\n";
    printf("入力: \"%s\", 数値=12345\n", format);
    ft_len = ft_printf(format, 12345);
    std_len = printf("printf:    %d\n", 12345);
    compare_length(ft_len, std_len, "%d", format);
    
    // %i テスト
    printf("\n%s----- %%i テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %i\n";
    printf("入力: \"%s\", 数値=-9876\n", format);
    ft_len = ft_printf(format, -9876);
    std_len = printf("printf:    %i\n", -9876);
    compare_length(ft_len, std_len, "%i", format);
    
    // %u テスト
    printf("\n%s----- %%u テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %u\n";
    printf("入力: \"%s\", 数値=UINT_MAX\n", format);
    ft_len = ft_printf(format, UINT_MAX);
    std_len = printf("printf:    %u\n", UINT_MAX);
    compare_length(ft_len, std_len, "%u", format);
    
    // %x テスト
    printf("\n%s----- %%x テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %x\n";
    printf("入力: \"%s\", 数値=0xABCDEF\n", format);
    ft_len = ft_printf(format, 0xABCDEF);
    std_len = printf("printf:    %x\n", 0xABCDEF);
    compare_length(ft_len, std_len, "%x", format);
    
    // %X テスト
    printf("\n%s----- %%X テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %X\n";
    printf("入力: \"%s\", 数値=0xabcdef\n", format);
    ft_len = ft_printf(format, 0xabcdef);
    std_len = printf("printf:    %X\n", 0xabcdef);
    compare_length(ft_len, std_len, "%X", format);
    
    // %% テスト
    printf("\n%s----- %%%% テスト -----%s\n", YELLOW, RESET);
    format = "ft_printf: %%\n";
    printf("入力: \"%s\"\n", format);
    ft_len = ft_printf(format);
    std_len = printf("printf:    %%\n");
    compare_length(ft_len, std_len, "%%", format);
}

// エッジケースのテスト
void test_edge_cases(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== エッジケースのテスト =====%s\n", BLUE, RESET);
    
    // NULLポインタ
    printf("\n%s----- NULL文字列テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %s\n", NULL);
    std_len = printf("printf:    %s\n", NULL);
    compare_length(ft_len, std_len, "NULL %s", "ft_printf: %s\n");
    
    // 空文字列
    printf("\n%s----- 空文字列テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %s\n", "");
    std_len = printf("printf:    %s\n", "");
    compare_length(ft_len, std_len, "empty %s", "ft_printf: %s\n");
    
    // INT_MIN
    printf("\n%s----- INT_MIN テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d\n", INT_MIN);
    std_len = printf("printf:    %d\n", INT_MIN);
    compare_length(ft_len, std_len, "INT_MIN", "ft_printf: %d\n");
    
    // INT_MAX
    printf("\n%s----- INT_MAX テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d\n", INT_MAX);
    std_len = printf("printf:    %d\n", INT_MAX);
    compare_length(ft_len, std_len, "INT_MAX", "ft_printf: %d\n");
    
    // NULLポインタ（%p）
    printf("\n%s----- NULL ポインタ（%%p）テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %p\n", NULL);
    std_len = printf("printf:    %p\n", NULL);
    compare_length(ft_len, std_len, "NULL %p", "ft_printf: %p\n");
}

// 複合フォーマットのテスト
void test_combined_formats(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 複合フォーマットのテスト =====%s\n", BLUE, RESET);
    
    // 複合テスト1
    printf("\n%s----- 複合テスト1 -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: 文字[%c] 文字列[%s] 数値[%d] 16進数[%x]\n", 'Z', "test", 42, 255);
    std_len = printf("printf:    文字[%c] 文字列[%s] 数値[%d] 16進数[%x]\n", 'Z', "test", 42, 255);
    compare_length(ft_len, std_len, "複合1", "ft_printf: 文字[%c] 文字列[%s] 数値[%d] 16進数[%x]\n");
    
    // 複合テスト2
    printf("\n%s----- 複合テスト2 -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: 複数の数値: %d, %i, %u, %x, %X\n", 123, -456, 789, 255, 255);
    std_len = printf("printf:    複数の数値: %d, %i, %u, %x, %X\n", 123, -456, 789, 255, 255);
    compare_length(ft_len, std_len, "複合2", "ft_printf: 複数の数値: %d, %i, %u, %x, %X\n");
}

// 連続したパーセント記号のテスト
void test_consecutive_percent(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 連続したパーセント記号のテスト =====%s\n", BLUE, RESET);
    
    ft_len = ft_printf("ft_printf: %%%%%%\n");
    std_len = printf("printf:    %%%%%%\n");
    compare_length(ft_len, std_len, "連続%%", "ft_printf: %%%%%%\n");
}

// テスト結果のサマリーを表示
void print_summary(void)
{
    printf("\n%s===== テスト結果サマリー =====%s\n", BLUE, RESET);
    printf("実行テスト数: %d\n", g_test_count);
    
    if (g_test_passed == g_test_count)
    {
        printf("%s全テスト成功! %d/%d [100%%]%s\n", 
              GREEN, g_test_passed, g_test_count, RESET);
    }
    else
    {
        printf("%sテスト結果: %d/%d [%.1f%%] 成功%s\n", 
              (g_test_passed > g_test_count / 2) ? YELLOW : RED,
              g_test_passed, g_test_count,
              (g_test_passed * 100.0) / g_test_count, RESET);
    }
}

// 数値の特殊ケーステスト
void test_special_numbers(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 数値の特殊ケーステスト =====%s\n", BLUE, RESET);
    
    // ゼロ値テスト
    printf("\n%s----- ゼロ値テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: 整数0[%d] 16進数0[%x][%X]\n", 0, 0, 0);
    std_len = printf("printf:    整数0[%d] 16進数0[%x][%X]\n", 0, 0, 0);
    compare_length(ft_len, std_len, "ゼロ値", "ft_printf: 整数0[%d] 16進数0[%x][%X]\n");
    
    // 負の16進数
    printf("\n%s----- 負の16進数テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %%x[%x] %%X[%X]\n", -42, -42);
    std_len = printf("printf:    %%x[%x] %%X[%X]\n", -42, -42);
    compare_length(ft_len, std_len, "負の16進数", "ft_printf: %%x[%x] %%X[%X]\n");
    
    // 大きな値
    printf("\n%s----- 大きな値テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %%u[%u] %%x[%x]\n", UINT_MAX, UINT_MAX);
    std_len = printf("printf:    %%u[%u] %%x[%x]\n", UINT_MAX, UINT_MAX);
    compare_length(ft_len, std_len, "大きな値", "ft_printf: %%u[%u] %%x[%x]\n");
}

// 特殊な文字列テスト
void test_special_strings(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 特殊な文字列テスト =====%s\n", BLUE, RESET);
    
    // 非常に長い文字列
    char long_str[1000];
    for (int i = 0; i < 999; i++)
        long_str[i] = 'a' + (i % 26);
    long_str[999] = '\0';
    
    // 特殊文字を含む文字列
    printf("\n%s----- 特殊文字テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%s]\n", "タブ\t改行\n特殊文字");
    std_len = printf("printf:    [%s]\n", "タブ\t改行\n特殊文字");
    compare_length(ft_len, std_len, "特殊文字", "ft_printf: [%s]\n");
}

// 複数の連続変換指定子テスト
void test_consecutive_specifiers(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 連続した変換指定子テスト =====%s\n", BLUE, RESET);
    
    printf("\n%s----- 連続指定子テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d%s%c\n", 42, "test", '!');
    std_len = printf("printf:    %d%s%c\n", 42, "test", '!');
    compare_length(ft_len, std_len, "連続指定子", "ft_printf: %d%s%c\n");
    
    printf("\n%s----- 同一指定子連続テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %c%c%c%c\n", 'a', 'b', 'c', 'd');
    std_len = printf("printf:    %c%c%c%c\n", 'a', 'b', 'c', 'd');
    compare_length(ft_len, std_len, "同一指定子連続", "ft_printf: %c%c%c%c\n");
}

// 境界値テスト
void test_boundary_cases(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 境界値テスト =====%s\n", BLUE, RESET);
    
    // 指定子のみ
    printf("\n%s----- 指定子のみテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d\n", 42);
    std_len = printf("printf:    %d\n", 42);
    compare_length(ft_len, std_len, "指定子のみ", "ft_printf: %d\n");
    
    // 空文字列フォーマット
    printf("\n%s----- 空文字列フォーマットテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("");
    std_len = printf("");
    compare_length(ft_len, std_len, "空文字列フォーマット", "");
    
    // 末尾%
    printf("\n%s----- 末尾%%テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: Test%");
    std_len = printf("printf:    Test%");
    printf("\n");  // 改行を追加
    compare_length(ft_len, std_len, "末尾%", "ft_printf: Test%");
}

// エラー処理テスト (ft_printfによっては実装が異なる)
void test_error_handling(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== エラー処理テスト =====%s\n", BLUE, RESET);
    
    // 認識されないフォーマット指定子
    printf("\n%s----- 未知の指定子テスト -----%s\n", YELLOW, RESET);
    printf("※ このテストはft_printfの実装により結果が異なる場合があります\n");
    ft_len = ft_printf("ft_printf: %z\n");
    std_len = printf("printf:    %z\n");
    compare_length(ft_len, std_len, "未知の指定子", "ft_printf: %z\n");
    // 認識されないフォーマット指定子
    printf("\n%s----- 未知の指定子テスト ver2 -----%s\n", YELLOW, RESET);
    printf("※ このテストはft_printfの実装により結果が異なる場合があります\n");
    ft_len = ft_printf("ft_printf: %q%%\n");
    std_len = printf("printf:    %q%%\n");
    compare_length(ft_len, std_len, "未知の指定子", "ft_printf: %q\n");
}

// ボーナス: フラグと幅/精度の組み合わせテスト
void test_bonus_flags_width_precision(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== ボーナス: フラグと幅/精度のテスト =====%s\n", BLUE, RESET);
    
    // 最小フィールド幅のテスト
    printf("\n%s----- 最小フィールド幅テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%5d] [%10s]\n", 42, "hello");
    std_len = printf("printf:    [%5d] [%10s]\n", 42, "hello");
    compare_length(ft_len, std_len, "最小フィールド幅", "ft_printf: [%5d] [%10s]\n");
    
    // 左揃えフラグ (-) テスト
    printf("\n%s----- 左揃えフラグテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%-5d] [%-10s]\n", 42, "hello");
    std_len = printf("printf:    [%-5d] [%-10s]\n", 42, "hello");
    compare_length(ft_len, std_len, "左揃えフラグ", "ft_printf: [%-5d] [%-10s]\n");
    
    // ゼロパディング (0) テスト
    printf("\n%s----- ゼロパディングテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%05d] [%010d]\n", 42, -42);
    std_len = printf("printf:    [%05d] [%010d]\n", 42, -42);
    compare_length(ft_len, std_len, "ゼロパディング", "ft_printf: [%05d] [%010d]\n");
    
    // 精度指定子 (.) テスト
    printf("\n%s----- 精度指定子テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%.3d] [%.5s]\n", 42, "hello");
    std_len = printf("printf:    [%.3d] [%.5s]\n", 42, "hello");
    compare_length(ft_len, std_len, "精度指定子", "ft_printf: [%.3d] [%.5s]\n");
    
    // 幅と精度の組み合わせテスト
    printf("\n%s----- 幅と精度の組み合わせテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%8.3d] [%10.5s]\n", 42, "hello");
    std_len = printf("printf:    [%8.3d] [%10.5s]\n", 42, "hello");
    compare_length(ft_len, std_len, "幅と精度", "ft_printf: [%8.3d] [%10.5s]\n");
    
    // 複雑な組み合わせテスト
    printf("\n%s----- 複雑な組み合わせテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%-8.3d] [%08.5d] [%-10.7s]\n", 42, 42, "hello");
    std_len = printf("printf:    [%-8.3d] [%08.5d] [%-10.7s]\n", 42, 42, "hello");
    compare_length(ft_len, std_len, "複雑な組み合わせ", "ft_printf: [%-8.3d] [%08.5d] [%-10.7s]\n");
}

// ボーナス: 特殊フラグ (# +) のテスト
void test_bonus_special_flags(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== ボーナス: 特殊フラグ (# +) のテスト =====%s\n", BLUE, RESET);
    
    // # フラグテスト (16進数)
    printf("\n%s----- # フラグテスト (16進数) -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%#x] [%#X]\n", 42, 42);
    std_len = printf("printf:    [%#x] [%#X]\n", 42, 42);
    compare_length(ft_len, std_len, "# フラグ (16進数)", "ft_printf: [%#x] [%#X]\n");
    
    // # フラグテスト (0値)
    printf("\n%s----- # フラグテスト (0値) -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%#x] [%#X]\n", 0, 0);
    std_len = printf("printf:    [%#x] [%#X]\n", 0, 0);
    compare_length(ft_len, std_len, "# フラグ (0値)", "ft_printf: [%#x] [%#X]\n");
    
    // + フラグテスト
    printf("\n%s----- + フラグテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+d] [%+i]\n", 42, -42);
    std_len = printf("printf:    [%+d] [%+i]\n", 42, -42);
    compare_length(ft_len, std_len, "+ フラグ", "ft_printf: [%+d] [%+i]\n");
    
    // スペースフラグテスト
    printf("\n%s----- スペースフラグテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [% d] [% i]\n", 42, -42);
    std_len = printf("printf:    [% d] [% i]\n", 42, -42);
    compare_length(ft_len, std_len, "スペースフラグ", "ft_printf: [% d] [% i]\n");
    
    // フラグの優先順位テスト (+ と スペース)
    printf("\n%s----- フラグ優先順位テスト (+ とスペース) -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+ d] [% +i]\n", 42, 42);
    std_len = printf("printf:    [%+ d] [% +i]\n", 42, 42);
    compare_length(ft_len, std_len, "+ とスペース", "ft_printf: [%+ d] [% +i]\n");
    
    // 複合フラグテスト
    printf("\n%s----- 複合フラグテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+8d] [% 8d] [%#8x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+8d] [% 8d] [%#8x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "複合フラグ", "ft_printf: [%+8d] [% 8d] [%#8x]\n");
    
    // 1. 文字列精度（精度が文字列長を超える）
    printf("\n%s----- 文字列精度10テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%.10s]\n", "abc");
    std_len = printf("printf:    [%.10s]\n", "abc");
    compare_length(ft_len, std_len, "文字列精度10", "ft_printf: [%.10s]\n");

    // 2. 幅＋精度（文字列）
    printf("\n%s----- 幅8精度5 文字列テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%8.5s]\n", "HelloWorld");
    std_len = printf("printf:    [%8.5s]\n", "HelloWorld");
    compare_length(ft_len, std_len, "幅8精度5 文字列", "ft_printf: [%8.5s]\n");

    // 3. 幅のみ（整数）
    printf("\n%s----- 幅5 整数テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%5d]\n", 123);
    std_len = printf("printf:    [%5d]\n", 123);
    compare_length(ft_len, std_len, "幅5 整数", "ft_printf: [%5d]\n");

    // 4. 幅＋精度（整数）
    printf("\n%s----- 幅6精度4 整数テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%6.4d]\n", 42);
    std_len = printf("printf:    [%6.4d]\n", 42);
    compare_length(ft_len, std_len, "幅6精度4 整数", "ft_printf: [%6.4d]\n");

    // 5. 左揃えフラグ＋幅＋精度（整数）
    printf("\n%s----- 左揃え 幅6精度4 テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%-6.4d]\n", 42);
    std_len = printf("printf:    [%-6.4d]\n", 42);
    compare_length(ft_len, std_len, "左揃え 幅6精度4", "ft_printf: [%-6.4d]\n");

    // 6. ゼロパディング＋精度（整数）
    printf("\n%s----- ゼロパディング 幅6精度4 テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%06.4d]\n", 42);
    std_len = printf("printf:    [%06.4d]\n", 42);
    compare_length(ft_len, std_len, "ゼロパディング 幅6精度4", "ft_printf: [%06.4d]\n");

    // 7. 精度のみ（16進数）
    printf("\n%s----- 精度4 16進数テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%.4x]\n", 0xA);
    std_len = printf("printf:    [%.4x]\n", 0xA);
    compare_length(ft_len, std_len, "精度4 16進数", "ft_printf: [%.4x]\n");

    // 8. 幅＋精度（16進数）
    printf("\n%s----- 幅6精度4 16進数テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%6.4x]\n", 0xAB);
    std_len = printf("printf:    [%6.4x]\n", 0xAB);
    compare_length(ft_len, std_len, "幅6精度4 16進数", "ft_printf: [%6.4x]\n");

    // 9. スペースフラグ＋幅＋精度（整数）
    printf("\n%s----- スペース 幅6精度3 テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [% 6.3d]\n", 7);
    std_len = printf("printf:    [% 6.3d]\n", 7);
    compare_length(ft_len, std_len, "スペース 幅6精度3", "ft_printf: [% 6.3d]\n");

    // 10. プラスフラグ＋幅＋精度（整数）
    printf("\n%s----- + 幅6精度3 テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+6.3d]\n", 7);
    std_len = printf("printf:    [%+6.3d]\n", 7);
    compare_length(ft_len, std_len, "+ 幅6精度3", "ft_printf: [%+6.3d]\n");

    printf("\n%s----- incorrect case 1-----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+m6.3d]\n", 7);
    std_len = printf("printf:    [%+m6.3d]\n", 7);
    compare_length(ft_len, std_len, "+ 幅6精度3", "ft_printf: [%+m6.3d]\n");


    printf("\n%s----- incorrect case 2-----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+m%m6.3d]\n");
    std_len = printf("printf:    [%+m%m6.3d]\n");
    compare_length(ft_len, std_len, "+ 幅6精度3", "ft_printf: [%+m%m6.3d]\n");

    printf("\n%s----- incorrect case 3-----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%m%%m6.3d]\n");
    std_len = printf("printf:    [%m%%m6.3d]\n");
    compare_length(ft_len, std_len, "+ 幅6精度3", "ft_printf: [%m%%m6.3d]\n");

    printf("\n%s----- %% オプション付きテスト -----\n%s", YELLOW, RESET);
    
}

void test_bonus_persent(void)
{
    int ft_len, std_len;
    
    // ゼロ埋め + 幅5
    ft_len = ft_printf("ft_printf: [%05%]\n");
    std_len = printf("printf:    [%05%]\n");
    compare_length(ft_len, std_len, "ゼロ埋め・幅5", "ft_printf: [%05%]");
    
    // 左寄せ + 幅6
    ft_len = ft_printf("ft_printf: [%-6%]\n");
    std_len = printf("printf:    [%-6%]\n");
    compare_length(ft_len, std_len, "左寄せ・幅6", "ft_printf: [%-6%]");
    
    // 幅だけ指定（幅3）
    ft_len = ft_printf("ft_printf: [%3%]\n");
    std_len = printf("printf:    [%3%]\n");
    compare_length(ft_len, std_len, "幅3のみ", "ft_printf: [%3%]");
    
    // 幅だけ指定（幅1）
    ft_len = ft_printf("ft_printf: [%1%]\n");
    std_len = printf("printf:    [%1%]\n");
    compare_length(ft_len, std_len, "幅1のみ", "ft_printf: [%1%]");
    
    // 何もオプションをつけずに%
    ft_len = ft_printf("ft_printf: [%%]\n");
    std_len = printf("printf:    [%%]\n");
    compare_length(ft_len, std_len, "標準的な%出力", "ft_printf: [%%]");
    
    // 無効な精度指定（標準printfと差が出やすい）
    ft_len = ft_printf("ft_printf: [%.3%]\n");
    std_len = printf("printf:    [%.3%]\n");
    compare_length(ft_len, std_len, "精度3指定（無効の可能性あり）", "ft_printf: [%.3%]");
}

void    test_bonus_all_flag(void)
{
    int ft_len, std_len;
    // すべてのフラグの組み合わせテスト
    printf("\n%s----- すべてのフラグ組み合わせテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+-8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+-8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "すべてのフラグ", "ft_printf: [%+-8.3d] [%+08.5d] [%#-8.3x]\n");
    // すべてのフラグの組み合わせテスト
    printf("\n%s----- すべてのフラグ組み合わせテスト[n] -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+-\n8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+-\n8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "すべてのフラグ", "ft_printf: [%+-\n8.3d] [%+08.5d] [%#-8.3x]\n");


    printf("\n%s----- すべてのフラグ組み合わせテスト [t]-----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+-\t8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+-\t8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "すべてのフラグ", "ft_printf: [%+-\t8.3d] [%+08.5d] [%#-8.3x]\n");


    printf("\n%s----- すべてのフラグ組み合わせテスト [  ]-----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+-  8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+-  8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "すべてのフラグ", "ft_printf: [%+-  8.3d] [%+08.5d] [%#-8.3x]\n");


    printf("\n%s----- すべてのフラグ組み合わせテスト [v]-----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+-\v8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+-\v8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "すべてのフラグ", "ft_printf: [%+-\v8.3d] [%+08.5d] [%#-8.3x]\n");

    printf("\n%s----- すべてのフラグ組み合わせテスト [f]-----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+-\f8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+-\f8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "すべてのフラグ", "ft_printf: [%+-\f8.3d] [%+08.5d] [%#-8.3x]\n");

    printf("\n%s----- すべてのフラグ組み合わせテスト [r]-----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+-\r8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+-\r8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "すべてのフラグ", "ft_printf: [%+-\r8.3d] [%+08.5d] [%#-8.3x]\n");
    
}

int main(void)
{
    printf("\n%s***** ft_printf テストプログラム *****%s\n", BLUE, RESET);
    
    test_format_specifiers();
    test_edge_cases();
    test_combined_formats();
    test_consecutive_percent();
    
    // 追加テスト
    test_special_numbers();
    test_special_strings();
    test_consecutive_specifiers();
    test_boundary_cases();
    test_error_handling();
    
    // ボーナステスト (ボーナス版でのみ成功します)
    printf("\n%s***** ボーナス機能テスト *****%s\n", BLUE, RESET);
    printf("%s注意: 以下のテストはボーナス版でのみ正常に動作します。%s\n", YELLOW, RESET);
    test_bonus_flags_width_precision();
    test_bonus_special_flags();
    test_bonus_persent();
    test_bonus_all_flag();
    
    print_summary();
    
    printf("\n%s***** テスト終了 *****%s\n\n", BLUE, RESET);
    return (0);
}