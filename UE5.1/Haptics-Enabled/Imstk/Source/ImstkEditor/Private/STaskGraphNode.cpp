// Fill out your copyright notice in the Description page of Project Settings.


#include "STaskGraphNode.h"
#include "GraphEditorSettings.h"
#include "SGraphPin.h"
//#include "EditorStyleSet.h"

// TODO: modify the graph pins to look better
class STaskGraphPin : public SGraphPin
{
public:
	SLATE_BEGIN_ARGS(STaskGraphPin) {}
	SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, UEdGraphPin* InPin)
	{
		this->SetCursor(EMouseCursor::Default);

		bShowLabel = true;

		GraphPinObj = InPin;
		check(GraphPinObj != nullptr);

		const UEdGraphSchema* Schema = GraphPinObj->GetSchema();
		check(Schema);

		SBorder::Construct(SBorder::FArguments()
			.BorderImage(this, &STaskGraphPin::GetPinBorder)
			.BorderBackgroundColor(this, &STaskGraphPin::GetPinColor)
			.OnMouseButtonDown(this, &STaskGraphPin::OnPinMouseDown)
			.Cursor(this, &STaskGraphPin::GetPinCursor)
			.Padding(FMargin(5.0f))
		);
	}

protected:
	virtual FSlateColor GetPinColor() const override
	{
		return FLinearColor(0.2, 0.2, 0.2);
	}

	virtual TSharedRef<SWidget>	GetDefaultValueWidget() override
	{
		return SNew(STextBlock);
	}

	const FSlateBrush* GetPinBorder() const
	{
		return FAppStyle::GetBrush(TEXT("Graph.StateNode.Body"));
	}

};



void STaskGraphNode::Construct(const FArguments& InArgs, UEdTaskGraphNode* InNode)
{
	GraphNode = InNode;
	UpdateGraphNode();
}

void STaskGraphNode::UpdateGraphNode() {
	const FMargin NodePadding = FMargin(5);
	const FMargin NamePadding = FMargin(2);
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	FLinearColor TitleShadowColor(0.6f, 0.6f, 0.6f);
	TSharedPtr<SErrorText> ErrorText;
	TSharedPtr<SVerticalBox> NodeBody;
	TSharedPtr<SNodeTitle> NodeTitle = SNew(SNodeTitle, GraphNode);

	UEdTaskGraphNode* TaskGraphNode = Cast<UEdTaskGraphNode>(GraphNode);

	this->ContentScale.Bind(this, &SGraphNode::GetContentScale);
	this->GetOrAddSlot(ENodeZone::Center)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.StateNode.Body"))
		.Padding(0.0f)
		.BorderBackgroundColor(this, &STaskGraphNode::GetBorderBackgroundColor)
		[
			SNew(SOverlay)

			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SVerticalBox)

			// Input Pin Area
		+ SVerticalBox::Slot()
		.FillHeight(1)
		[
			SAssignNew(LeftNodeBox, SVerticalBox)
		]

	// Output Pin Area	
	+ SVerticalBox::Slot()
		.FillHeight(1)
		[
			SAssignNew(RightNodeBox, SVerticalBox)
		]
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(8.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.StateNode.Body"))
		.BorderBackgroundColor(TaskGraphNode->TaskGraphNode.Color)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Visibility(EVisibility::SelfHitTestInvisible)
		.Padding(6.0f)
		[
			SAssignNew(NodeBody, SVerticalBox)

			// Title
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			// Node Title
		+SHorizontalBox::Slot()
		.Padding(FMargin(4.0f, 0.0f, 4.0f, 0.0f))
		.MaxWidth(TaskGraphNode->TaskGraphNode.Name.Len() * 10)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TaskGraphNode->TaskGraphNode.Name))
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		[
			NodeTitle.ToSharedRef()
		]
		]
		]
		]
		]
		]
		];
	CreatePinWidgets();
}

void STaskGraphNode::CreatePinWidgets()
{
	UEdTaskGraphNode* StateNode = CastChecked<UEdTaskGraphNode>(GraphNode);

	UEdGraphPin* InPin = StateNode->GetInputPin();
	TSharedPtr<SGraphPin> NewInPin = SNew(STaskGraphPin, InPin);
	NewInPin->GetPinObj()->Direction = EGPD_Input;

	UEdGraphPin* OutPin = StateNode->GetOutputPin();
	TSharedPtr<SGraphPin> NewOutPin = SNew(STaskGraphPin, OutPin);
	NewOutPin->GetPinObj()->Direction = EGPD_Output;

	AddPin(NewInPin.ToSharedRef());
	AddPin(NewOutPin.ToSharedRef());
}

FSlateColor STaskGraphNode::GetBorderBackgroundColor() const
{
	return FLinearColor::Black;
}


FSlateColor STaskGraphNode::GetBackgroundColor() const
{
	return FLinearColor(0.1f, 0.1f, 0.1f);
}

EVisibility STaskGraphNode::GetDragOverMarkerVisibility() const
{
	return EVisibility::Visible;
}
