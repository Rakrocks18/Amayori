$$
\begin{align}
[\text{Prog}] &\to [\text{Stmt}]^*
\\
[\text{Stmt}] &\to
\begin{cases}
\text{return}(\text{[Expr]})\\
\text{let} \space \text{ident} = [\text{Expr}]
\end{cases}

\\
[\text{Expr}] &\to
\begin{cases}
\text{int} \\
\text{ident} \\
\text{[BinaryExpr]}
\end{cases}
\\
[\text{BinaryExpr}] &\to
\begin{cases}
[\text{Expr}] / [\text{Expr}] & \text{prec} = 3\\
[\text{Expr}] * [\text{Expr}] & \text{prec} = 2\\    [\text{Expr}] + [\text{Expr}] & \text{prec} = 1\\
[\text{Expr}] - [\text{Expr}] & \text{prec} = 0\\    
\end{cases}
\end{align}
$$