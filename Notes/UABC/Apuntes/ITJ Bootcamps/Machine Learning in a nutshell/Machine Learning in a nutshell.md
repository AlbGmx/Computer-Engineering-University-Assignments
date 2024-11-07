# Intelligence vs Artificial Intelligence, Machine Learning, Applications and limitations, AI governance, ML pipeline

---

## Intelligence

- The ability learn, understand and think in a logical way about things; the ability to do this well. - Oxford
- The ability to acquire and apply knowledge and skills. - Google Search
- Intelligence is a complex and multifaceted concept that encompasses various cognitive abilities and traits. Broadly, it refers to the capacity to learn from experience, adapt to new situation, understand and handle abstract concepts, and use knowledge to manipulate one’s environment. - ChatGPT
- Basically, there’s no real definition

## Evolution of Artificial intelligence

AI is a generic term that refers to any machine or algorithm that is capable of observing its environment, learning, and based on the knowledge and experience gained, taking intelligent action or proposing decisions. There are many different technologies that fall under this broad AI definition. At the moment, **Machine Learning** techniques are the most widely used.

- 1940s - 1950s
    - Foundations of AI
    - Turing tests
- 1960s - 1970s
    - Eliza - Chatbot
    - Dendral - expert system
    - Misky’s 3 to 8 years prediction on AGI
- 1980s AI winter
    - Reduced funding
    - Expert systems
    - Back-propagation
- 1990s
    - Same code more power
    - IBM Deep Blue
    - LOOM project, Tokens!
    - Emergence of ML
- 2000s
    - Deep Learning
    - GANs
    - Roomba
- 2010s
    - Rise of AI
    - NLP
    - Watson
    - Siri, Alexa
    - AlphaGo
    - DeepMind Cats
    - DeepFace facebook
    - EU Ethic guidelines
- 2020s Generative AI Boom
    - GPT-3
    - Llama
    - Bard
    - Gemini

## Machine Learning

Patterns from data → Models from patterns → Prediction from models

### Applications

- Recommendation systems
- Medical diagnosis
- Fault detection
- Fi8nancial predictions
- Visual and auditory recognition
- Industrial processes prediction
- Text analysis
- Code generation

### Limitations

- A machine learning model is not humanly intelligent
- Far from creating models with cognitive capabilities similar to humans
- AI models are capable of solving very specific p[problems, in some cases even better than humans
- We should have a clear justification to implement an AI model, not just because everyone is doing it
- Is ChatGPT the end? **Definitely not**

### AI Governance

- Rector of UN University (T. Marwala), in 2023 explains that:
    - AI has become a part of our daily existence, in health, education, finance and entertainment
    - Efficient and effective governance strategies will be necessary to:
        - Ensure impartiality
        - Guarantee transparency
        - Protect privacy
        - Maintain and promote democratic access to technology
        - Promote trust in AI systems
- The ethical use of technology must be promoted and guaranteed in **all fields**, as established by the WHO for its use in medical matters
- Consider extreme cases can help us focus our possible concerns
- There are many risk with AI, particularly in military uses
- Autonomous systems with AI can take action without human intervention, but:
    - Can an AI weapon satisfactorily distinguish a civilian from a combatant?  
        Who is responsible?  
        
- Military use of AI
    - Is ethical or moral?

### European Union AI Act

- Minimal Risk
    - No regulation
    - Most applications
    - AI in video games
    - Spam filters
- Limited Risk
    - Risk of impersonation or deception
    - Generative AI
    - Transparency
    - OpenAI not happy
- High Risk
    - High risk to health, safety, environment and fundamental rights
    - Risk assessment, logs, interpretability and explicability, human oversight
- Unacceptable Risk

### ML Pipeline

- Data Preparation
    - Collection
    - Processing
    - Feature Engineering
- Model Building
    - Model selection
    - Training
    - Evaluation
    - Hyper-parameter tuning
- Model Deployment
    - Deployment
    - Monitoring
    - Maintenance

# The classification problem, the importance of data, Visualization, Feature Engineering

---

https://drive.google.com/file/d/1FF06y19_qz1c9Djom-ufX5mBP7-jsOAM/view?usp=drive_web

## ML Basic Concepts

- Basic Machine Learning concepts:
    - **Observations:** samples collected from the phenomenon being studied
    - **Target:** labels related to the samples that identify them
    - **Features:** attributes or distinctive aspects of the samples that allow them to be identified
    - **Training:** inferring a model using a set of samples
    - **Prediction:** given a new observation, using the trained model assign it a label

## The Classification Problem

- In ML it all start with a training set of ordered pairs
- $T=\{(\vec{x_{i1}})\}$﻿, where:
    - Each $\vec{x_i} = (x_{i1}, x_{i2}, \ldots, x_{im})$﻿ represents an observation, and is usually represented by a vector of size $m$﻿, where each element $x_{ij}$﻿ is a descriptive trait (**feature**), input, predictor or independent variable.
    - $y_i$﻿ represents the label, output, or dependent variable; in a **classification problem**, these are **discrete values**
    - The goal of an ML algorithm for classification is to estimate a function (model/hypothesis) $h: X \rightarrow Y$﻿, so that $h(\vec{x_i}) = y_i$﻿, not only for the observations in $T$﻿ but for unknown observations (**test data)**.
    - In general, the output of a classification model can be:
        - Directly a class label, as in KNN
        - A real number, where the class label is defined with a threshold
        - a class membership probability $ P_c \in [0,1] $﻿ for each class $c$﻿; the label is assigned to the class with the highest probability
- Given an **observation**, the model must predict the **label** of the class to which it belongs:
    - Binary classification
    - Multi-class classification
    - Multi-label classification
    - Imbalanced classification

$\begin{array}{c}$

$\text{\textbf{Input}} \rightarrow \text{\textbf{Machine Learning Algorithm}} \rightarrow \text{\textbf{Output}} \\$

## **Data Preparation**

- **Collection**
- Procedures
- Feature engineering

## Data Collection

- What data do we need and where can we get it?
- Legal or ethical restrictions
- Obtain access
- Review space requirements
- Convert the data to a forma appropriate for manipulation by the software and review the data type
- Store and organize data
- Safety and accessibility

## The Importance of Data

- Data is the foundation op
- Garbage in Garbage out

![[Untitled 4.png|Untitled 4.png]]

## Curse of Dimensionality

![[Untitled 1 2.png|Untitled 1 2.png]]

## Data Processing

- Data Cleaning
- Transform for model usage
- Data separation train/test
- Data problems:
    - Missing data
    - outlier detection
    - Sensitive data
- Normalization and scaling
- Most of our time!
    
    ### Pandas
    
    - Specialized library for working with data sets
    - Main functions are:
        - Analyzing
        - Cleaning
        - Exploring
        - manipulating data
    
    **Data series**
    
    - A sequence of data “The column of a table”
    - One dimensional array of objects
    
    ```Python
    import pandas as pd
    a = [1, 7,2]
    myvar = pd.Series(a)
    ```
    
    **Data**
    
    - something
    - something
    - something
    

## Data Processing

### Survey - Explore

- `Head()`
- `Tail()`
- `Info()`
- `Describe()`
- Frequency - `value_counts()`

### Visualizations

Pandas has tools for easy visualization of data

- Basic plot → `data.plot()`
- XY plotting → `data.plot(x = 'Longitude', y = 'Lalitude)'`
- Histogram → `data['ocean_proximity'].hist()`
- Boxplot → `data['longitude'].plot.box`
- Density plot → `data['latitude'].plot.kde`
- Area plot→ `data[['total_bedroms', 'households']].plot.area()`
- Scatter plot → `data.plot.scatter(x = 'median_income', y = 'total_rooms')`
    - Scatter different groups 
        
        ```Python
        ax = data.iloc[:100].plot.scatter(x = 'median_income', y = 'total_rooms', color = 'red', label = 'Group 1')
        data.iloc[101:200].plot.scatter(x = 'median_income', y = 'total_rooms', color = 'blue', label = 'Group 2', ax=ax)
        ```
        
    - Color scale 
        
        ```Python
        data.iloc[:100].plot.scatter(x='median_income', y='total_rooms', c='median_house_value')
        data['ocean_proximity'].replace(['<1H OCEAN', 'INLAND', 'NEAR OCEAN', 'NEAR BAY', 'ISLAND'], [0,1,2,3,4], inplace=True)
        data.plot.scatter(x='median_income', y='total_rooms', c='ocean_proximity', cmap="viridis", s=50)
        data.plot.scatter(x='longitude', y = 'latitude')
        ```
        
- Hex bin plot (heat map) → `data.plot.hexbin(x='median_income', y='total_rooms',gridsize=25)`

### Composite Visualizations

- Scatter matrix
    
    ```Python
    from pandas.plotting import scatter_matrix
    scatter_matrix(data.iloc[:500])
    scatter_matrix(data.iloc[:500], alpha=0.2, figsize=(6, 6), diagonal="kde")
    ```
    

### Multidimensional Plotting

- Andrews curves
    
    ```Python
    from pandas.plotting import andrews_curves
    andrews_curves(data.iloc[:1000],'ocean_proximity')
    
    iris =  pd.read_csv('./datasets/iris.data', header=None)
    andrews_curves(iris, 4)
    ```
    
- Parallel Coordinates
    
    ```Python
    from pandas.plotting import parallel_coordinates
    data.drop(['median_house_value'], axis=1, inplace=True)
    parallel_coordinates(data, 'ocean_proximity')
    parallel_coordinates(iris, 4);
    ```
    
- Radviz plot
    
    ```Python
    from pandas.plotting import radviz
    radviz(iris, 4);
    ```
    

## Feature Engineering

Better features / better data >> More Complex models

- Dimensionality reduction
- Feature Extraction
    - Identify Prominent features
        
        ![[Untitled 2 2.png|Untitled 2 2.png]]
        
- Feature Selection
- Feature Transformation

![[Untitled 3 2.png|Untitled 3 2.png]]

# Model selection, training and evaluation, model deployment, model control

---

## Model Building

- Model Selection
- Training
- Evaluation
- Hyperparameter tuning

## Model Selection

Binary Classification

Multiclass Classification

Multilabel Classification

  

# Course project (UCSD credits)

---