\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{minitelreport}[2024/11/13 Minitel Report Class]

\LoadClass[french]{report}
	\setcounter{secnumdepth}{4}

% Utilitaire LaTeX
\RequirePackage{etoolbox}
\RequirePackage{ifthen}

\RequirePackage[top=3cm, bottom=3cm, left=3cm, right=3cm]{geometry}

% Caractères et symboles de texte (+ csquotes après minted pour éviter un warning)
	\RequirePackage{lmodern}
	\RequirePackage[T1]{fontenc}
	\RequirePackage[french]{babel}
	\RequirePackage{hyphenat}
	\RequirePackage{textcomp}
	\RequirePackage[normalem]{ulem}
	\RequirePackage{pifont}

%%%%%%%%%%%%%%
% Graphismes %
%%%%%%%%%%%%%%

% Couleurs de Minitel
\RequirePackage[table, dvipsnames]{xcolor}
	\definecolor{minitelgreen1}{rgb}{0.56, 0.75, 0.07}
	\definecolor{minitelgreen3}{rgb}{0.0, 0.5, 0.0}
	\definecolor{minitelgreen2}{rgb}{0.29, 0.63, 0.004}
	\definecolor{minitelgreen4}{rgb}{0.93, 0.96, 0.84}

% Images et SVG
\RequirePackage{graphicx}
\RequirePackage{svg}

% Ornementations
\RequirePackage{pgfornament-han}

%%%%%%%%%
% Maths %
%%%%%%%%%

\RequirePackage{tikz}
\RequirePackage{pgfplots}
\pgfplotsset{compat=1.18}
\RequirePackage{amssymb}

%command for alg-closure that automatically adapts its 'bar' to the arg based on the args length (including '\')
\newcommand{\ols}[1]{\mskip.5\thinmuskip\overline{\mskip-.5\thinmuskip {#1} \mskip-.5\thinmuskip}\mskip.5\thinmuskip} % overline short
\newcommand{\olsi}[1]{\,\overline{\!{#1}}} % overline short italic
\makeatletter
\newcommand\closure[1]{
  \tctestifnum{\count@stringtoks{#1}>1} %checks if number of chars in arg > 1 (including '\')
  {\ols{#1}} %if arg is longer than just one char, e.g. \mathbb{Q}, \mathbb{F},...
  {\olsi{#1}} %if arg is just one char, e.g. K, L,...
}
% FROM TOKCYCLE:
\long\def\count@stringtoks#1{\tc@earg\count@toks{\string#1}}
\long\def\count@toks#1{\the\numexpr-1\count@@toks#1.\tc@endcnt}
\long\def\count@@toks#1#2\tc@endcnt{+1\tc@ifempty{#2}{\relax}{\count@@toks#2\tc@endcnt}}
\def\tc@ifempty#1{\tc@testxifx{\expandafter\relax\detokenize{#1}\relax}}
\long\def\tc@earg#1#2{\expandafter#1\expandafter{#2}}
\long\def\tctestifnum#1{\tctestifcon{\ifnum#1\relax}}
\long\def\tctestifcon#1{#1\expandafter\tc@exfirst\else\expandafter\tc@exsecond\fi}
\long\def\tc@testxifx{\tc@earg\tctestifx}
\long\def\tctestifx#1{\tctestifcon{\ifx#1}}
\long\def\tc@exfirst#1#2{#1}
\long\def\tc@exsecond#1#2{#2}
\makeatother

\RequirePackage{amsmath}
\RequirePackage{bbm}
\RequirePackage{stmaryrd}
\RequirePackage{tikz}

%%%%%%%%%%%%%%%%
% Informatique %
%%%%%%%%%%%%%%%%

% Pour les algorithmes
\RequirePackage[lined,boxed,commentsnumbered, ruled,vlined,linesnumbered, french, onelanguage]{algorithm2e}
	\SetNlSty{}{}{}
	\let\oldnl\nl% Store \nl in \oldnl
	\newcommand\nonl{%
	  \renewcommand{\nl}{\let\nl\oldnl}}% Remove line number for one line
	\SetKwComment{Comment}{/* }{ */}

% Pour les arborescences de fichiers
\RequirePackage{forest}
	\forestset{default preamble={for tree={
			font=\ttfamily,
			grow'=0,
			child anchor=west,
			parent anchor=south,
			anchor=west,
			calign=first,
			edge path={
				\noexpand\path [draw, \forestoption{edge}]
				(!u.south west) +(7.5pt,0) |- node[fill,inner sep=1.25pt] {} (.child anchor)\forestoption{edge label};
			},
			before typesetting nodes={
				if n=1
					{insert before={[,phantom]}}
					{}
			},
			fit=band,
			before computing xy={l=15pt},
		}}
	}

% Pour surtitrer et référencer les codes
\RequirePackage{listings}

% Pour les échantillons de codes colorés syntaxiquement
\RequirePackage[newfloat]{minted2}
	\definecolor{mintedsourcebackground}{rgb}{0.97,0.97,0.97}
	\definecolor{mintedterminalbackground}{rgb}{0., 0., 0.}
	\setminted[c]{
		bgcolor=mintedsourcebackground,
		frame=leftline,
		framerule=0.4pt,
		framesep=2mm,
		tabsize=2,
		obeytabs=true,
		linenos=true,
		numberblanklines=true,
		numbersep=5pt,
		fontfamily=tt,
		fontsize=\small
	}

	\setminted[nasm]{
		bgcolor=mintedsourcebackground,
		frame=leftline,
		framerule=0.4pt,
		framesep=2mm,
		tabsize=2,
		obeytabs=true,
		linenos=true,
		numberblanklines=true,
		numbersep=5pt,
		fontfamily=tt,
		fontsize=\small
	}

	\setminted[make]{
		bgcolor=mintedsourcebackground,
		frame=leftline,
		framerule=0.4pt,
		framesep=2mm,
		tabsize=2,
		obeytabs=true,
		linenos=true,
		numberblanklines=true,
		numbersep=5pt,
		fontfamily=tt,
		fontsize=\small
	}

	\setminted[bash]{
		frame=single,
		obeytabs=false,
		linenos=false,
		fontfamily=tt,
		fontsize=\small,
	}

\RequirePackage{csquotes}

%%%%%%%%%%%%%%%%
% Mise en page %
%%%%%%%%%%%%%%%%
\RequirePackage{setspace}
\RequirePackage{tocloft}

\makeatletter
	\newcommand\HUGE{\@setfontsize\Huge{50}{60}}
\makeatother

\makeatletter
\renewcommand{\@chapapp}{}% Not necessary...
\newenvironment{chapquote}[2][2em]
  {\setlength{\@tempdima}{#1}%
   \def\chapquote@author{#2}%
   \parshape 1 \@tempdima \dimexpr\textwidth-2\@tempdima\relax%
   \itshape}
  {\par\normalfont\hfill--\ \chapquote@author\hspace*{\@tempdima}\par\bigskip}
\makeatother

\RequirePackage{fancyhdr}
	\setlength{\headheight}{15.2pt}
	\pagestyle{fancyplain}
	\fancyhf{}
	\makeatletter
	\lhead{ \fancyplain{}{\@title\:\@subtitle} }
	\makeatother
	\rhead{ \fancyplain{}{\rightmark} }
	\rfoot{ \fancyplain{}{\thepage} }

% Jolies sections
\RequirePackage{titlesec}
\newcommand{\marginsecnumber}[1]{%
  \makebox[0pt][r]{#1\hspace{6pt}}%
}

\newcommand{\makeornament}[1]{
	\rlap{\pgfornamenthan[ydelta=-25pt, height=.75cm, color=minitelgreen2]{9}}\pgfornamenthan[ydelta=10pt, symmetry=h, height=.75cm, color=minitelgreen2]{9}
	~#1\unskip~
	\pgfornamenthan[ydelta=-25pt, height=.75cm, symmetry=v, color=minitelgreen2]{9}\llap{\pgfornamenthan[ydelta=10pt, symmetry=c, height=.75cm, color=minitelgreen2]{9}}
}

	\titleformat{\part}[block]
	{\centering}
	{\huge Partie \thepart\\}
	{0pt}
	{\HUGE\scshape}

	\titleformat{\section}[block]
	{\centering}
	{}
	{0pt}
	{\huge\scshape\protect\makeornament}

	\titleformat{\subsection}
  {\normalfont\large\bfseries}
  {\color{minitelgreen3}\marginsecnumber\thesubsection}
  {0pt}
  {\color{minitelgreen3}\Large\bfseries}

  \titleformat{\subsubsection}
  {\normalfont\bfseries}
  {}
  {0pt}
  {\color{minitelgreen3}\large\bfseries}

% Jolis chapitres
\RequirePackage[Rejne]{fncychap}

% Extension pour la gestion des paragraphes
\RequirePackage[skip=10pt plus1pt, indent=0pt]{parskip}

% Extension pour les tabulations et espaces
\RequirePackage{tabto}

% Meilleur gestion des alignements
\RequirePackage{ragged2e}

% Faire des jolis boîtes
\RequirePackage{tcolorbox}
	\newtcolorbox{minitelbasicbox}[2][]
	{
	  colframe = minitelgreen3,
	  colback  = minitelgreen1!30!white,
	  coltitle = white,  
	  title    = {#2},
	  #1,
	}

% Pour multiplier les options d'énumération de type itemize ou enumerate
\RequirePackage[shortlabels]{enumitem}
	\setlist[itemize, 1]{font=\color{minitelgreen3}, label=\ding{110}}
	\setlist[itemize, 2]{font=\color{minitelgreen2}, label=\textbullet}
	\setlist[itemize, 3]{font=\color{minitelgreen1}, label=\ding{117}}

% Page de garde
\makeatletter
\newcommand\variant[1]{\renewcommand\@variant{Version #1}}
\newcommand\@variant{}
\newcommand\subtitle[1]{\renewcommand\@subtitle{#1}}
\newcommand\@subtitle{}
\newcommand\licence[1]{\renewcommand\@licence{#1}}
\newcommand\@licence{}
\renewcommand{\maketitle}{
	\begin{tikzpicture}[remember picture,overlay]
        \node[xshift=-108mm, yshift=151.5mm] at (current page.center)
        {%
            \begin{tikzpicture}[remember picture,overlay]
			    \node [shading = axis,rectangle, left color=minitelgreen1, right color=minitelgreen3,shading angle=-135, anchor=north, minimum width=\paperwidth, minimum height=\paperheight] (box) at (current page.north){};
			  \end{tikzpicture}
        };
    \end{tikzpicture}
    \color{white}
	\pagenumbering{gobble}
	\begin{minipage}{0.5\textwidth}
	\large
	\textbf{\@date}
	\end{minipage}
	\begin{minipage}{0.5\textwidth}
	\raggedleft
	\textbf{\@author}
	\end{minipage}
	\vspace*{0.5\fill}
	\begin{center}
		\linespread{3}

		\HUGE
		
		\textbf{\@title}
		
		\huge
		
		\textbf{\@subtitle}
		
		\normalsize
		
		\@variant
	\end{center}
	\begin{minipage}{\textwidth}
		\begin{center}
			\includesvg[height=6cm]{images/logo_minitel}
		\end{center}
	\end{minipage}
	\vspace*{\fill}

	\Large
	\begin{minipage}{0.3\textwidth}
	\linespread{1}
	\raggedright
	\includesvg[width=6cm]{images/logo_ecole}
	\end{minipage}
	\begin{minipage}{0.7\textwidth}
	\raggedleft
	\large
	\textbf{\@licence}
	\end{minipage}
	\newpage
	\normalsize
	\color{black}
	\pagenumbering{arabic}
}
\makeatother

%%%%%%%%%%%%%%%%%
% Miscellaneous %
%%%%%%%%%%%%%%%%%

% Pour sous-titrer les images et autres figures
\RequirePackage{caption}
	\captionsetup{hypcap=false}

% Liens hypertexte
\RequirePackage{bookmark} % Inclut hyperref par défaut
\hypersetup{
	colorlinks=true,
	urlcolor=blue!80!black,
	citecolor=PineGreen,
	linkcolor=minitelgreen2!70!black
}

\RequirePackage{makecell}