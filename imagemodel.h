
#define IMAGEMODEL_H


#include <QAbstractListModel>
#include <QVector>
#include <QUrl>

class ImageModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum ImageRoles {
        ImageUrlRole = Qt::UserRole + 1
    };

    explicit ImageModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addImage(const QUrl& imageUrl);

private:
    QVector<QUrl> m_images;
};
ImageModel::ImageModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

int ImageModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_images.size();
}

QVariant ImageModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= m_images.size() || index.row() < 0) {
        return QVariant();
    }

    if (role == ImageUrlRole) {
        return m_images[index.row()];
    }

    return QVariant();
}

QHash<int, QByteArray> ImageModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ImageUrlRole] = "imageUrl";
    return roles;
}

void ImageModel::addImage(const QUrl& imageUrl)
{
    beginInsertRows(QModelIndex(), m_images.size(), m_images.size());
    m_images.append(imageUrl);
    endInsertRows();
}
