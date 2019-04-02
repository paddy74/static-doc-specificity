# Formulas

The following describes the formulas used in this project.

## Document Specificity

<a href="https://www.codecogs.com/eqnedit.php?latex=S(d)=\frac{1}{l_{d}}\sum_{t_{i}\epsilon&space;d}^{&space;}tf(t_{i})BASE" target="_blank"><img src="https://latex.codecogs.com/gif.latex?S(d)=\frac{1}{l_{d}}\sum_{t_{i}\epsilon&space;d}^{&space;}tf(t_{i})BASE" title="S(d)=\frac{1}{l_{d}}\sum_{t_{i}\epsilon d}^{ }tf(t_{i})BASE" /></a>

## NIDF base

The higher the value of *S*, the more specific the document is (*higher values are better*).

### Inverse document frequency

Defined as the logarithmic ratio of the total number of documents in a collection (<a href="https://www.codecogs.com/eqnedit.php?latex=n_{d}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?n_{d}" title="n_{d}" /></a>) to the number of documents containing the term (<a href="https://www.codecogs.com/eqnedit.php?latex=df(t_{i})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?df(t_{i})" title="df(t_{i})" /></a>).

<a href="https://www.codecogs.com/eqnedit.php?latex=IDF(t_{i})=log(\frac{n_{d}}{df(t_{i})})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?IDF(t_{i})=log(\frac{n_{d}}{df(t_{i})})" title="IDF(t_{i})=log(\frac{n_{d}}{df(t_{i})})" /></a>

### Normalized inverse document frequency

Normalized IDF with respect to the number of documents not containing the term (<a href="https://www.codecogs.com/eqnedit.php?latex=n_{d}-df(t_{i})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?n_{d}-df(t_{i})" title="n_{d}-df(t_{i})" /></a>) and adds a constant *0.5* to the numerator and the denominator in order to moderate extreme values.

<a href="https://www.codecogs.com/eqnedit.php?latex=NIDF(t_{i})=log(\frac{n_{d}-df(t_{i})&plus;0.5}{df(t_{i})&plus;0.5})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?NIDF(t_{i})=log(\frac{n_{d}-df(t_{i})&plus;0.5}{df(t_{i})&plus;0.5})" title="NIDF(t_{i})=log(\frac{n_{d}-df(t_{i})+0.5}{df(t_{i})+0.5})" /></a>

## Term entropy base

The lower the value of *S*, the more specific the document is (*lower values are better*).

### Information entropy

The information entropy of a discrete random variable *X* with possible values {<a href="https://www.codecogs.com/eqnedit.php?latex=x_{1},x_{2},...,x_{n}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_{1},x_{2},...,x_{n}" title="x_{1},x_{2},...,x_{n}" /></a>} is defined as:

<a href="https://www.codecogs.com/eqnedit.php?latex=H(X)=-\sum_{i=1}^{n}Pr_{X}(x_{i})log(Pr_{X}(x_{i}))" target="_blank"><img src="https://latex.codecogs.com/gif.latex?H(X)=-\sum_{i=1}^{n}Pr_{X}(x_{i})log(Pr_{X}(x_{i}))" title="H(X)=-\sum_{i=1}^{n}Pr_{X}(x_{i})log(Pr_{X}(x_{i}))" /></a>

### Probability distribution function

<a href="https://www.codecogs.com/eqnedit.php?latex=Pr_{t_{i}}(d_{j})=\frac{tf(d_{j})}{tf(c)}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Pr_{t_{i}}(d_{j})=\frac{tf(d_{j})}{tf(c)}" title="Pr_{t_{i}}(d_{j})=\frac{tf(d_{j})}{tf(c)}" /></a>

### Term entropy

Therefore the information entropy of a term <a href="https://www.codecogs.com/eqnedit.php?latex=t_{i}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?t_{i}" title="t_{i}" /></a> is:

<a href="https://www.codecogs.com/eqnedit.php?latex=H(t_{i})=-\sum_{j=1}^{n_{d}}Pr_{t_{i}}(d_{j})log(Pr_{t_{i}}(d_{j}))" target="_blank"><img src="https://latex.codecogs.com/gif.latex?H(t_{i})=-\sum_{j=1}^{n_{d}}Pr_{t_{i}}(d_{j})log(Pr_{t_{i}}(d_{j}))" title="H(t_{i})=-\sum_{j=1}^{n_{d}}Pr_{t_{i}}(d_{j})log(Pr_{t_{i}}(d_{j}))" /></a>
