#!/usr/bin/env perl
# https://neerc.ifmo.ru/wiki/index.php?title=%D0%98%D0%B7%D0%B1%D1%8B%D1%82%D0%BE%D1%87%D0%BD%D0%BE%D0%B5_%D0%BA%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5,_%D0%BA%D0%BE%D0%B4_%D0%A5%D1%8D%D0%BC%D0%BC%D0%B8%D0%BD%D0%B3%D0%B0#:~:text=%D0%98%D0%B7%D0%B1%D1%8B%D1%82%D0%BE%D1%87%D0%BD%D0%BE%D0%B5%20%D0%BA%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5%20(%D0%B0%D0%BD%D0%B3%D0%BB.,%D0%B5%D1%91%20%D0%BF%D0%B5%D1%80%D0%B5%D0%B4%D0%B0%D1%87%D0%B5%20%D0%BF%D0%BE%20%D0%BB%D0%B8%D0%BD%D0%B8%D1%8F%D0%BC%20%D1%81%D0%B2%D1%8F%D0%B7%D0%B8.
use v5.010;
use strict;
use warnings;
#use integer;
use List::Util qw(sum all);
use POSIX;

sub log2 {
    return log(shift) / log(2);
}

sub ctrl {
    my $x = 0;
    for my $e (@_) { 
        $x ^= $e;
    }
    return $x;
}

sub sm { 
    my ($k, $bit, @s) = @_;
    return sum(
        map { $s[$_] } grep { (($_ >> $k) & 1) == $bit } 0..$#s
    ) % 2;
}

sub getcode {
    my @c = ();
    for my $k (0 .. ceil(log2(scalar(@_))) - 1) {
    	push @c, (sm($k, 0, @_), sm($k, 1, @_));
    }
    return (@c, ctrl(@c));
}

my $t = <>;
my $r = <>; chomp $r;
my @s = split "", $r;
#my @s = split "", (join "", map { chomp $_; $_ } <>);
#my @s = split "", sub {} -> (<>);


if ($t == 1) {
    print @s, getcode(@s), "\n";
    exit(0);
}

my $n = 0;
for my $k (0..$#s) { # 2 ^ k + 2k = n
    $n = scalar(@s) - 2 * $k - 1;
    last if (ceil(log2($n)) == $k);
}

my @x = @s[0..$n - 1];
my @y = @s[$n..$#s];

#print @x,'|',@y,"\n";

my @gc = getcode(@x);
if (all { $y[$_] eq $gc[$_] } (0..$#y - 1)) {
    print @x, "\n";
    exit(0);
}

if (ctrl(@y[0..$#y - 1]) != $y[-1]) {
    print @x, "\n";
    exit(0);
}


my $p = 0;
for my $k (0 .. int(scalar(@y) / 2) - 1) {
    $p *= 2;
    $p++ if $y[2 * $k + 1] != sm($k, 1, @x);
}

$x[$p] ^= 1;
print @x, "\n";


# 10010110
# 110101100000000
=f
sub lol {
 my $s = sub { shift };
 return $s->(10);
}
print lol { shift() + 10 };



sub lol {
 my $s = sub { shift };
 return $s->($_ = 10);
}
print lol { $_ + 10 };


sub lol {
 my $s = shift;
 return $s->(10);
}
print(lol sub { shift() + 10 });
=cut
