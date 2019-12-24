[TOC]

# [Diagrams](https://shd101wyy.github.io/markdown-preview-enhanced/#/diagrams)

## [Mermaid](https://github.com/mermaid-js/mermaid)

> 注：从配置中搜索'mermaid'，然后可以选择渲染时使用的主题

### [流程图](http://mermaid-js.github.io/mermaid/#/flowchart)
```mermaid
graph LR
A[Hard] -->|Text| B(Round)
B --> C{Decision}
C -->|One| D[Result 1]
C -->|Two| E[Result 2]
```

### [顺序图](http://mermaid-js.github.io/mermaid/#/sequenceDiagram)
```mermaid
sequenceDiagram
Alice->>John: Hello John, how are you?
loop Healthcheck
    John->>John: Fight against hypochondria
end
Note right of John: Rational thoughts!
John-->>Alice: Great!
John->>Bob: How about you?
Bob-->>John: Jolly good!
```

### [甘特图](http://mermaid-js.github.io/mermaid/#/gantt)
```mermaid
gantt
section Section
Completed :done,    des1, 2014-01-06,2014-01-08
Active        :active,  des2, 2014-01-07, 3d
Parallel 1   :         des3, after des1, 1d
Parallel 2   :         des4, after des1, 1d
Parallel 3   :         des5, after des3, 1d
Parallel 4   :         des6, after des4, 1d
```

### [类图](http://mermaid-js.github.io/mermaid/#/classDiagram)
```mermaid
 classDiagram
      Animal <|-- Duck
      Animal <|-- Fish
      Animal <|-- Zebra
      Animal : +int age
      Animal : +String gender
      Animal: +isMammal()
      Animal: +mate()
      class Duck{
          +String beakColor
          +swim()
          +quack()
      }
      class Fish{
          -int sizeInFeet
          -canEat()
      }
      class Zebra{
          +bool is_wild
          +run()
      }
```

### [状态图](http://mermaid-js.github.io/mermaid/#/stateDiagram)
```mermaid
stateDiagram
[*] --> Still
Still --> [*]
Still --> Moving
Moving --> Still
Moving --> Crash
Crash --> [*]
```

### [饼状图](http://mermaid-js.github.io/mermaid/#/pie)
```mermaid
pie
    title Key elements in Product X
    "Calcium" : 42.96
    "Potassium" : 50.05
    "Magnesium" : 10.01
    "Iron" :  5
```

## [PlantUML](https://plantuml.com/zh/)

### [用例图](https://plantuml.com/zh/use-case-diagram)
```puml
@startuml
left to right direction
skinparam packageStyle rectangle
actor customer
actor clerk
rectangle checkout {
  customer -- (checkout)
  (checkout) .> (payment) : include
  (help) .> (checkout) : extends
  (checkout) -- clerk
}
@enduml
```

### [活动图](https://plantuml.com/zh/activity-diagram-legacy)
```puml
@startuml
title Servlet Container

(*) --> "ClickServlet.handleRequest()"
--> "new Page"

if "Page.onSecurityCheck" then
  ->[true] "Page.onInit()"
  
  if "isForward?" then
   ->[no] "Process controls"
   
   if "continue processing?" then
	 -->[yes] ===RENDERING===
   else
	 -->[no] ===REDIRECT_CHECK===
   endif
   
  else
   -->[yes] ===RENDERING===
  endif
  
  if "is Post?" then
	-->[yes] "Page.onPost()"
	--> "Page.onRender()" as render
	--> ===REDIRECT_CHECK===
  else
	-->[no] "Page.onGet()"
	--> render
  endif
  
else
  -->[false] ===REDIRECT_CHECK===
endif

if "Do redirect?" then
 ->[yes] "redirect request"
 --> ==BEFORE_DESTROY===
else
 if "Do Forward?" then
  -left->[yes] "Forward request"
  --> ==BEFORE_DESTROY===
 else
  -right->[no] "Render page template"
  --> ==BEFORE_DESTROY===
 endif
endif

--> "Page.onDestroy()"
-->(*)

@enduml
```

### [组件图](https://plantuml.com/zh/component-diagram)
```puml
@startuml

package "Some Group" {
  HTTP - [First Component]
  [Another Component]
}
 
node "Other Groups" {
  FTP - [Second Component]
  [First Component] --> FTP
} 

cloud {
  [Example 1]
}


database "MySql" {
  folder "This is my folder" {
	[Folder 3]
  }
  frame "Foo" {
	[Frame 4]
  }
}


[Another Component] --> [Example 1]
[Example 1] --> [Folder 3]
[Folder 3] --> [Frame 4]

@enduml
```

### [类图](https://plantuml.com/zh/class-diagram)
```puml
@startuml
Object <|-- ArrayList

Object : equals()
ArrayList : Object[] elementData
ArrayList : size()

Class01 "1" *-- "many" Class02 : contains
Class03 o-- Class04 : aggregation
Class05 --> "1" Class06
@enduml
```

### [状态图](https://plantuml.com/zh/state-diagram)
```puml
@startuml
scale 600 width

[*] -> State1
State1 --> State2 : Succeeded
State1 --> [*] : Aborted
State2 --> State3 : Succeeded
State2 --> [*] : Aborted
state State3 {
  state "Accumulate Enough Data\nLong State Name" as long1
  long1 : Just a test
  [*] --> long1
  long1 --> long1 : New Data
  long1 --> ProcessData : Enough Data
}
State3 --> State3 : Failed
State3 --> [*] : Succeeded / Save Result
State3 --> [*] : Aborted
 
@enduml
```

### [时序图](https://plantuml.com/zh/sequence-diagram)
```puml
@startuml
Alice -> Bob: Authentication Request

alt successful case

	Bob -> Alice: Authentication Accepted
	
else some kind of failure

	Bob -> Alice: Authentication Failure
	group My own label
		Alice -> Log : Log attack start
	    loop 1000 times
	        Alice -> Bob: DNS Attack
	    end
		Alice -> Log : Log attack end
	end
	
else Another type of failure

   Bob -> Alice: Please repeat
   
end
@enduml
```